#ifndef OPTIONPRICER_H
#define OPTIONPRICER_H

#include <vector>
#include <functional>
#include "StockTree.h"

class OptionPricer {
public:
    enum OptionType { Call, Put };
    enum Style { European, American };

    OptionPricer(double S0, double K, double r, double sigma, double deltaT, int N,
                 OptionType type = Call, Style style = European,
                 std::function<double(double, double)> payoff = nullptr);

    void price();
    const std::vector<std::vector<double>>& getStockTree() const;
    const std::vector<std::vector<double>>& getOptionTree() const;
    double getC0() const;

private:
    double K, r, sigma, deltaT;
    int N;
    Style style;
    double u, d, q;
    std::function<double(double, double)> payoff;
    std::vector<std::vector<double>> optionVals;
    StockTree stockTree;
    void computeRiskNeutral();
    void buildOptionTree();
    double S0;
    OptionType type;
};

#endif // OPTIONPRICER_H 