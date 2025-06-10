#include "BinomialTree.h"  // Include your class header
#include "StockTree.h"

int main() {
    // Create trees
    BinomialTree tree1(3, {
        {1},
        {0.0, 0.0},
        {0.0, 0.0, 0.0}
    });

    BinomialTree tree2(5);
    StockTree tree3(3, 100.0, 1.2, 0.8);

    // Display 'em
    tree1.displayTree();
    tree2.displayTree();
    tree3.displayTree();

    return 0;
}
