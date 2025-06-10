#include "StockTree.h"
#include <cassert>     // For assert()
#include <cmath>       // For std::pow

// Constructor that initializes the stock tree
StockTree::StockTree(int N, double initialS0, double upFactor, double downFactor)
    : BinomialTree(N), // N periods, N+1 levels
      S0(initialS0),     // Initialize member S0 with initialS0 parameter
      u(upFactor),       // Initialize member u with upFactor parameter
      d(downFactor)      // Initialize member d with downFactor parameter
{
    // Assertions should ideally be on the parameters directly for clarity
    // and because they are the immediate source of the values.
    assert(N >= 0 && "Number of periods N must be >= 0");
    assert(N + 1 <= 11 && "N+1 must be <= 11");
    assert(initialS0 > 0 && "Initial stock price must be greater than 0");
    assert(upFactor > 1 && "Up factor must be greater than 1");
    assert(downFactor < 1 && "Down factor must be less than 1");

    // Call the build method after all members are initialized and validated
    buildStockTree();
}

void StockTree::buildStockTree() {
    assert(vals.size() == static_cast<size_t>(N + 1) && "vals should have N+1 levels");
    for (size_t i = 0; i < static_cast<size_t>(N + 1); ++i) {
        assert(vals[i].size() == i + 1 && "Each level of vals should have i+1 elements");
        for (size_t j = 0; j <= i; ++j) {
            vals[i][j] = S0 * std::pow(u, static_cast<double>(j)) * std::pow(d, static_cast<double>(i - j));
        }
    }
}