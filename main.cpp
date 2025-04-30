#include <iostream>
#include "avl_tree.hpp"

// Generate Fibonacci numbers
void generate_fibonacci(int n, int* fib) {
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    AVLTree tree;
    const int num_fibonacci = 25;
    int fibonacci[num_fibonacci];
    
    // Generate first 25 Fibonacci numbers
    generate_fibonacci(num_fibonacci, fibonacci);
    
    // Insert Fibonacci numbers into the AVL tree
    std::cout << "Inserting first " << num_fibonacci << " Fibonacci numbers into the AVL tree" << std::endl;
    for (int i = 0; i < num_fibonacci; i++) {
        tree.insert(fibonacci[i]);
        std::cout << "Inserted: " << fibonacci[i] << std::endl;
    }
    
    // Print tree information
    std::cout << "\nTree size: " << tree.size() << std::endl;
    std::cout << "Tree height: " << tree.height() << std::endl;
    
    // Print tree in different traversal orders
    std::cout << "\nIn-order traversal: ";
    tree.print_in_order();
    
    std::cout << "Pre-order traversal: ";
    tree.print_pre_order();
    
    std::cout << "Post-order traversal: ";
    tree.print_post_order();
    
    return 0;
}