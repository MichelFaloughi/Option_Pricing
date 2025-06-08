#include "BinomialTree.h"  // Include your class header

int main() {
    // Create a tree of depth 3 with custom values
    BinomialTree tree1(3, {
        {0.0},
        {0.0, 0.0},
        {0.0, 0.0, 0.0}
    });

    // Create a tree of depth 5 filled with 0.0 automatically
    BinomialTree tree2(5);

    tree1.displayTree();
    tree2.displayTree();

    return 0;
}
