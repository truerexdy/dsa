#include "avl_trees.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    avl_tree tree;

    std::cout << "Inserting random values:\n";
    for (int i = 0; i < 6; ++i) {
        int val = std::rand() % 100;  // random values from 0 to 99
        std::cout << val << " ";
        tree.insert(val);
    }
    std::cout << "\n\nAVL Tree structure:\n";
    tree.display();

    return 0;
}
