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

// Test simple insertion
bool test_insertion() {
    // Setup
    AVLTree tree;
    
    // Execution
    bool result1 = tree.insert(50);
    bool result2 = tree.insert(25);
    bool result3 = tree.insert(75);
    
    // Validation
    assert(result1);
    assert(result2);
    assert(result3);
    assert(tree.size() == 3);
    assert(tree.contains(50));
    assert(tree.contains(25));
    assert(tree.contains(75));
    assert(!tree.contains(100));
    
    // Clean up
    return true;
}

// Test duplicate insertion
bool test_duplicate_insertion() {
    // Setup
    AVLTree tree;
    
    // Execution
    bool result1 = tree.insert(50);
    bool result2 = tree.insert(50);
    
    // Validation
    assert(result1);
    assert(!result2);
    assert(tree.size() == 1);
    
    // Clean up
    return true;
}

// Test left rotation, right heavy tree
bool test_left_rotation() {
    // Setup
    AVLTree tree;
    
    // Execution
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    
    // Validation
    assert(tree.size() == 3);
    assert(tree.height() == 2);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));
    
    // Clean up
    return true;
}

// Test right rotation, left heavy tree
bool test_right_rotation() {
    // Setup
    AVLTree tree;
    
    // Execution
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    
    // Validation
    assert(tree.size() == 3);
    assert(tree.height() == 2);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));
    
    // Clean up
    return true;
}

// Test left right rotation
bool test_left_right_rotation() {
    // Setup
    AVLTree tree;
    
    // Execution
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    
    // Validation
    assert(tree.size() == 3);
    assert(tree.height() == 2);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));
    
    // Clean up
    return true;
}

// Test right left rotation
bool test_right_left_rotation() {
    // Setup
    AVLTree tree;
    
    // Execution
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    
    // Validation
    assert(tree.size() == 3);
    assert(tree.height() == 2);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));
    
    // Clean up
    return true;
}

// Test removal of leaf node
bool test_remove_leaf() {
    // Setup
    AVLTree tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    
    // Execution
    bool result = tree.remove(25);
    
    // Validation
    assert(result);
    assert(tree.size() == 2);
    assert(tree.contains(50));
    assert(!tree.contains(25));
    assert(tree.contains(75));
    
    // Clean up
    return true;
}

// Test removal of node with one child
bool test_remove_one_child() {
    // Setup
    AVLTree tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(85);
    
    // Execution
    bool result = tree.remove(75);
    
    // Validation
    assert(result);
    assert(tree.size() == 3);
    assert(tree.contains(50));
    assert(tree.contains(25));
    assert(!tree.contains(75));
    assert(tree.contains(85));
    
    // Clean up
    return true;
}

// Test removal of node with two children
bool test_remove_two_children() {
    // Setup
    AVLTree tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(65);
    tree.insert(85);
    
    // Execution
    bool result = tree.remove(75);
    
    // Validation
    assert(result);
    assert(tree.size() == 4);
    assert(tree.contains(50));
    assert(tree.contains(25));
    assert(!tree.contains(75));
    assert(tree.contains(65));
    assert(tree.contains(85));
    
    // Clean up
    return true;
}

// Test removal of root
bool test_remove_root() {
    // Setup
    AVLTree tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    
    // Execution
    bool result = tree.remove(50);
    
    // Validation
    assert(result);
    assert(tree.size() == 2);
    assert(!tree.contains(50));
    assert(tree.contains(25));
    assert(tree.contains(75));
    
    // Clean up
    return true;
}

// Test multiple rotations after a series of insertions
bool test_multiple_rotations() {
    // Setup
    AVLTree tree;
    
    // Execution
    for (int i = 1; i <= 10; i++) {
        tree.insert(i);
    }
    
    // Validation
    assert(tree.size() == 10);
    assert(tree.height() <= 4);
    for (int i = 1; i <= 10; i++) {
        assert(tree.contains(i));
    }
    
    // Clean up
    return true;
}

// Run all tests
int main() {
    int passed = 0;
    int total = 0;
    
    // Define all tests
    struct Test {
        bool (*function)();
        const char* name;
    };
    
    Test tests[] = {
        {test_empty_tree, "Empty Tree Test"},
        {test_insertion, "Insertion Test"},
        {test_duplicate_insertion, "Duplicate Insertion Test"},
        {test_left_rotation, "Left Rotation Test"},
        {test_right_rotation, "Right Rotation Test"},
        {test_left_right_rotation, "Left-Right Rotation Test"},
        {test_right_left_rotation, "Right-Left Rotation Test"},
        {test_remove_leaf, "Remove Leaf Node Test"},
        {test_remove_one_child, "Remove Node with One Child Test"},
        {test_remove_two_children, "Remove Node with Two Children Test"},
        {test_remove_root, "Remove Root Node Test"},
        {test_multiple_rotations, "Multiple Rotations Test"}
    };
    
    total = sizeof(tests) / sizeof(tests[0]);
    
    // Run all tests
    for (int i = 0; i < total; i++) {
        std::cout << "Running " << tests[i].name << "... ";
        if (tests[i].function()) {
            std::cout << "PASSED" << std::endl;
            passed++;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
    
    // Print summary
    std::cout << "\nTest Summary: " << passed << "/" << total << " tests passed." << std::endl;
    
    return (passed == total) ? 0 : 1;
}