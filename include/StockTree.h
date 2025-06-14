#ifndef STOCKTREE_H
#define STOCKTREE_H

#include "BinomialTree.h"
#include <cmath>

class StockTree : public BinomialTree {

public:
    double S0;  // Initial stock price
    double u;   // Up factor
    double d;   // Down factor

    StockTree(int N, double S0, double u, double d);
    StockTree(const StockTree&) = delete;
    StockTree& operator=(const StockTree&) = delete;

private:
    void buildStockTree(); 
    
};

#endif // STOCKTREE_H