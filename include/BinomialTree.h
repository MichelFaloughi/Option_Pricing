#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#include <vector>

class BinomialTree {
protected:
    int N; // Number of periods
    std::vector<std::vector<double>> vals; // Values at each node

public:
    BinomialTree(int N);
    BinomialTree(int N, const std::vector<std::vector<double>>& v);
    virtual ~BinomialTree() = default;

    // Delete copy constructor and assignment operator to prevent accidental copying
    BinomialTree(const BinomialTree&) = delete;
    BinomialTree& operator=(const BinomialTree&) = delete;

    // Getters
    int getN() const { return N; }
    const std::vector<std::vector<double>>& getVals() const { return vals; }

    // Methods
    void displayTree() const;
    static std::vector<std::vector<double>> buildDefaultTreeFromDepth(int Nplus1);
};

#endif // BINOMIAL_TREE_H