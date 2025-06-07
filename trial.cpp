#include <iostream>
#include <vector>
#include <iomanip>  // for std::setw

int main() {
    int x = 5;
    std::vector<std::vector<double>> tree(x);

    // Fill the vector of vectors with example values
    for (int i = 0; i < x; ++i) {
        tree[i] = std::vector<double>(i + 1, 0.0);  // could fill with other values
    }

    // Print in binomial tree style
    for (int i = 0; i < x; ++i) {
        int spaces = (x - i - 1) * 2;
        std::cout << std::string(spaces, ' ');  // leading spaces

        for (double val : tree[i]) {
            std::cout << std::fixed << std::setprecision(1)
                      << std::setw(4) << val;
        }

        std::cout << "\n";
    }

    return 0;
}


// if possible we want this:

//           0        
//         0
//       0   0
//     0   0
//   0   0   0  
// 0   0   0
//   0   0   0  
//     0   0
//       0   0  
//         0
//           0  
