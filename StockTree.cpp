#include "StockTree.h"


// Constructor that initializes the stock tree
StockTree::StockTree(int dpt, double S0, double u, double d)
    : BinomialTree(dpt), S0(S0), u(u), d(d) {
    assert(dpt > 0 && "Depth must be greater than 0");
    assert(dpt <= 10 && "Depth must be less than or equal to 10");
    assert(S0 > 0 && "Initial stock price must be greater than 0");
    assert(u > 1 && "Up factor must be greater than 1");
    assert(d < 1 && "Down factor must be less than 1");
    buildStockTree();
}

