#include "BinomialTree.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;
using std::string;

// Constructor that accepts external values
BinomialTree::BinomialTree(int N, const vector<vector<double>>& v) {
    assert(N >= 0 && "Number of periods N must be >= 0");
    assert(static_cast<size_t>(N + 1) == v.size() && "Vector must match N+1 levels");
    for (size_t i = 0; i < v.size(); ++i) {
        assert(v[i].size() == i + 1 && "Each level must have i+1 elements");
    }
    this->N = N;
    this->vals = v;
}

// Build tree filled with 0.0 (default values)
vector<vector<double>> BinomialTree::buildDefaultTreeFromDepth(int Nplus1) {
    vector<vector<double>> result(Nplus1);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = vector<double>(i + 1, 0.0);
    }
    return result;
}

// Display tree in a triangle layout
void BinomialTree::displayTree() const {
    for (size_t i = 0; i < vals.size(); ++i) {
        int spaces = (static_cast<int>(vals.size()) - static_cast<int>(i) - 1) * 2;
        cout << string(spaces, ' ');
        for (double val : vals[i]) {
            cout << fixed << setprecision(1) << setw(4) << val;
        }
        cout << endl;
    }
}
