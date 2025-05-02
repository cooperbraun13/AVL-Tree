#include <iostream>
#include <cassert>
#include "avl_tree.hpp"

// Test empty tree
bool test_empty_tree() {
    // Setup
    AVLTree tree;

    // Execution

    // Validation
    assert(tree.is_empty());
    assert(tree.size() == 0);
    assert(tree.height() == 0);

    // Clean up
    return true;
}

// Test insertion
bool test_insertion() {
    // Setup
    AVLTree tree;

    // Execution
    bool result1 = tree.insert(10);
    bool result2 = tree.insert(25);
    bool result3 = tree.insert(50);

    // Validation
    assert(result1);
    assert(result2);
    assert(result3);
    assert(tree.size() == 3);
    assert(tree.contains(10));
    assert(tree.contains(25));
    assert(tree.contains(50));
    assert(!tree.contains(75));

    // Clean up
    return true;
}