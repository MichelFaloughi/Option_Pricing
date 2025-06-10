#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include <vector>
#include <cassert>

using std::vector;

class BinomialTree {
public:
    BinomialTree(int dpt);
    BinomialTree(int dpt, const vector<vector<double>>& v);
    void displayTree() const;

protected:
    int depth;
    vector<vector<double>> vals;

private:
    static vector<vector<double>> buildDefaultTreeFromDepth(int d);
};

#endif // BINOMIALTREE_H