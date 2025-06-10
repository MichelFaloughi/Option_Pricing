#include "OptionPricer.h"
#include <cmath>
#include <cassert>

OptionPricer::OptionPricer(double S0, double K, double r, double sigma, double deltaT, int N,
                         OptionType type, Style style,
                         std::function<double(double, double)> payoff)
    : S0(S0), K(K), r(r), sigma(sigma), deltaT(deltaT), N(N), type(type), style(style),
      stockTree(N, S0, std::exp(sigma * deltaT), std::exp(-sigma * deltaT))
{
    // Validate input parameters
    if (S0 <= 0) throw std::invalid_argument("Initial stock price must be positive");
    if (K <= 0) throw std::invalid_argument("Strike price must be positive");
    if (r < 0) throw std::invalid_argument("Risk-free rate cannot be negative");
    if (sigma <= 0) throw std::invalid_argument("Volatility must be positive");
    if (deltaT <= 0) throw std::invalid_argument("Time step must be positive");
    if (N <= 0) throw std::invalid_argument("Number of steps must be positive");

    if (!payoff) {
        if (type == Call)
            this->payoff = [](double S, double K) { return std::max(S - K, 0.0); };
        else
            this->payoff = [](double S, double K) { return std::max(K - S, 0.0); };
    } else {
        this->payoff = payoff;
    }
    computeRiskNeutral();
}

void OptionPricer::computeRiskNeutral() {
    u = std::exp(sigma * deltaT);
    d = std::exp(-sigma * deltaT);
    q = (std::exp(r * deltaT) - d) / (u - d);
}

void OptionPricer::price() {
    buildOptionTree();
}

void OptionPricer::buildOptionTree() {
    const auto& S = stockTree.getValues();
    
    // Pre-allocate the entire structure
    optionVals.clear();
    optionVals.resize(N + 1);
    for (size_t i = 0; i < optionVals.size(); ++i) {
        optionVals[i].resize(S[i].size());
    }
    
    // Terminal payoffs at level N
    size_t last = static_cast<size_t>(N);
    for (size_t j = 0; j < S[last].size(); ++j) {
        optionVals[last][j] = payoff(S[last][j], K);
    }
    
    // Backward induction
    for (int i = N - 1; i >= 0; --i) {
        for (size_t j = 0; j < S[i].size(); ++j) {
            // Calculate continuation value
            double continuationValue = std::exp(-r * deltaT) * 
                (q * optionVals[i+1][j+1] + (1 - q) * optionVals[i+1][j]);
            
            if (style == American) {
                // For American options, compare with immediate exercise value
                double exerciseValue = payoff(S[i][j], K);
                optionVals[i][j] = std::max(continuationValue, exerciseValue);
            } else {
                // For European options, just use continuation value
                optionVals[i][j] = continuationValue;
            }
        }
    }
}

const std::vector<std::vector<double>>& OptionPricer::getStockTree() const {
    return stockTree.getValues();
}

const std::vector<std::vector<double>>& OptionPricer::getOptionTree() const {
    return optionVals;
}

double OptionPricer::getC0() const {
    return optionVals.empty() ? 0.0 : optionVals[0][0];
} 