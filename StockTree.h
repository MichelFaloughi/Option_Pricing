#ifndef STOCKTREE_H
#define STOCKTREE_H

#include "BinomialTree.h"
#include <cmath>

class StockTree : public BinomialTree {

public:
    double S0;  // Initial stock price
    double u;   // Up factor
    double d;   // Down factor

    StockTree(int dpt, double S0, double u, double d)
        : BinomialTree(d)
        {
    }

private:
    void buildStockTree() {
        // Initialize the stock tree with the initial stock price
        vals.resize(depth);
        for (int i = 0; i < depth; ++i) {
            vals[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                vals[i][j] = S0 * pow(u, j) * pow(d, i - j);
            }
        }
    }
    
};

#endif // STOCKTREE_H