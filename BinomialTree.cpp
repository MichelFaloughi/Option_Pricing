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

// Constructor that builds the tree from depth
BinomialTree::BinomialTree(int dpt)
    : BinomialTree(dpt, buildTreeFromDepth(dpt)) {}

// Constructor that accepts external values
BinomialTree::BinomialTree(int dpt, const vector<vector<double>>& v) {
    assert(dpt > 0 && "Depth must be greater than 0");
    assert(dpt <= 10 && "Depth must be less than or equal to 10");
    assert(v.size() == dpt && "Vector must match depth");

    // Check that each subvector is size i + 1
    for (int i = 0; i < d; ++i) {
        assert(v[i].size() == i + 1 && "Each level must have i+1 elements");
    }

    this->depth = dpt;
    this->vals = v;
}

// Build tree filled with 0.0
vector<vector<double>> BinomialTree::buildTreeFromDepth(int d) {
    vector<vector<double>> result(d);
    for (int i = 0; i < d; ++i) {
        result[i] = vector<double>(i + 1, 0.0);
    }
    return result;
}

// Display tree in a triangle layout
void BinomialTree::displayTree() const {
    for (int i = 0; i < depth; ++i) {
        int spaces = (depth - i - 1) * 2;
        cout << string(spaces, ' ');
        for (double val : vals[i]) {
            cout << fixed << setprecision(1) << setw(4) << val;
        }
        cout << endl;
    }
}
