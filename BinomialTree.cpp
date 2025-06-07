// This class represents a Binomial Tree.
// Attributes:
//      - depth?
//      - vals

// Potential Methods:
//      - double getElem(int level, int height)
//      - void setElem(int level, int height)
//      - void displayTree()
//      - void addLevel or removeLevel or something
//      - vector<vector<double>> buildTreeFromDepth

// idk if all subtrees have the same branching proba for ALLLL binomial tree but if it's the case:
//      - void fill() - like fill all the nodes if doable idk yet well see.

// to do list:
// - make vals default to a vector of vector of nulls for now or just a vector of nulls in the constructor
// - make sure there is a size limit for the depth/level of trees
// - make sure each sub-vector's length in the vals vectors increase by 1 only


#include <iostream>
#include <vector>
#include <iomanip>  // for std::setw

using std::vector;

class BinomialTree {
    // attributes
    int depth;
    vector<vector<double>> vals; // this is a vector of vector of doubles

public:
    // constructor
    BinomialTree(int d, vector<vector<double>> v) {
        this->depth = d;
        this->vals = v;
    }

    // methods
    vector<vector<double>> buildTreeFromDepth(int depth) {
        vector<vector<double>> vals(depth);

        for (int i = 0; i < depth; ++i) {
            vals[i] = vector<double>(i+1, 0.0);
        }
    }


    void displayTree() {

        for (int i = 0; i < this->depth; ++i) {
        int spaces = (this->depth - i - 1) * 2;
        std::cout << std::string(spaces, ' ');  // leading spaces

        for (double val : this->vals[i]) {
            std::cout << std::fixed << std::setprecision(1)
                      << std::setw(4) << val;
        }

        std::cout << "\n";
        }
    }

};


int main() {
    
    BinomialTree tree = BinomialTree(3, vector<vector<double>>{
        {0.0},
        {0.0, 0.0},
        {0.0, 0.0, 0.0}
    });

    tree.displayTree();
    
    return 0;
}
