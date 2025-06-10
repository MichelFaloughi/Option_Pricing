#include "StockTree.h"
#include <cassert>     // For assert()
#include <cmath>       // For std::pow

// Constructor that initializes the stock tree
StockTree::StockTree(int dpt, double initialS0, double upFactor, double downFactor)
    : BinomialTree(dpt), // Call base constructor with depth
      S0(initialS0),     // Initialize member S0 with initialS0 parameter
      u(upFactor),       // Initialize member u with upFactor parameter
      d(downFactor)      // Initialize member d with downFactor parameter
{
    // Assertions should ideally be on the parameters directly for clarity
    // and because they are the immediate source of the values.
    assert(dpt > 0 && "Depth must be greater than 0");
    assert(dpt <= 10 && "Depth must be less than or equal to 10");
    assert(initialS0 > 0 && "Initial stock price must be greater than 0");
    assert(upFactor > 1 && "Up factor must be greater than 1");
    assert(downFactor < 1 && "Down factor must be less than 1");

    // Call the build method after all members are initialized and validated
    buildStockTree();
}

void StockTree::buildStockTree() {
    // ... (Your buildStockTree method as you provided, it's good) ...
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j <= i; ++j) {
            vals[i][j] = S0 * std::pow(u, j) * std::pow(d, i - j);
        }
    }
}