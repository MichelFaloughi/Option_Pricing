#include "BinomialTree.h"  // Include your class header
#include "StockTree.h"
#include "OptionPricer.h"
#include <iostream>
#include <iomanip>

void printTree(const std::vector<std::vector<double>>& tree, const std::string& title) {
    std::cout << title << std::endl;
    for (size_t i = 0; i < tree.size(); ++i) {
        for (size_t j = 0; j < tree[i].size(); ++j) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(2) << tree[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example parameters
    double S0 = 100.0;
    double K = 110.0;
    double r = 0.05;
    double sigma = 0.2;
    double deltaT = 1.0 / 3.0;
    int N = 3;

    OptionPricer pricer(S0, K, r, sigma, deltaT, N, OptionPricer::Call, OptionPricer::European);
    pricer.price();

    printTree(pricer.getStockTree(), "Stock Tree:");
    printTree(pricer.getOptionTree(), "Option Value Tree:");
    std::cout << "\nOption Price at t=0 (C0): " << pricer.getC0() << std::endl;



    return 0;
}

// test
