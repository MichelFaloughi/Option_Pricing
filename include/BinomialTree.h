#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

class BinomialTree {
public:
    // N is the number of periods, tree will have N+1 levels (from 0 to N)
    BinomialTree(int N) : N(N) {
        vals = vector<vector<double>>(N + 1);
        for (int i = 0; i <= N; ++i) {
            vals[i] = vector<double>(i + 1);
        }
    }
    BinomialTree(int N, const vector<vector<double>>& v);
    void displayTree() const;

    void setValues(const vector<vector<double>>& v) {
        assert(v.size() == N + 1 && "Vector must match N+1 levels");
        for (size_t i = 0; i < v.size(); ++i) {
            assert(v[i].size() == i + 1 && "Each level must have i+1 elements");
        }
        vals = v;
    }

    const vector<vector<double>>& getValues() const {
        return vals;
    }

    BinomialTree(const BinomialTree&) = delete;
    BinomialTree& operator=(const BinomialTree&) = delete;

protected:
    int N;
    vector<vector<double>> vals;

private:
    static vector<vector<double>> buildDefaultTreeFromDepth(int N);
};

#endif // BINOMIALTREE_H