# AVL Tree Implementation

## Overview

This project implements an AVL Tree (self-balancing binary search tree) with complete functionality for insertion, deletion, search, and tree traversal operations.

## File Structure

* `avltree.hpp` - Header file containing AVLNode and AVLTree class declarations
* `avltree.cpp` - Implementation of the AVL tree operations
* `main.cpp` - Demo program that inserts the first 25 Fibonacci numbers and prints the tree
* `test_avl_tree.cpp` - Unit tests for the AVL tree implementation

## Compilation Instructions

### Compile Main Program

```bash
g++ -std=c++11 main.cpp avltree.cpp -o main
```

### Compile Test Program

```bash
g++ -std=c++11 test_avl_tree.cpp avl_tree.cpp -o test
```

## Running The Programs

### Run The Main Program

```bash
./main
```

This will:

1. Insert the first 25 Fibonacci numbers into the AVL tree
2. Display the tree structure with height information
3. Show the inorder traversal to verify the BST property

### Run The Test Program

```bash
./test
```

This will run four test suites:

1. Insertion tests - verifies correct insertion and balancing
2. Deletion tests - verifies proper deletion and rebalancing
3. Rotation tests - tests all four rotation types
4. Search tests - verifies search functionality