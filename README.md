# AVL Tree Implementation

This is an implementation of an AVL Tree, which is a self-balancing binary search tree. After any insertion or deletion operation, the tree automatically maintains balance by ensuring that the height difference between left and right subtrees (balance factor) is at most 1 for all nodes.

## Files Included

- `avl_node.hpp` and `avl_node.cpp`: AVL tree node class
- `avl_tree.hpp` and `avl_tree.cpp`: AVL tree implementation
- `main.cpp`: Inserts the first 25 Fibonacci numbers and prints the tree
- `test_avl_tree.cpp`: Test cases for the AVL tree implementation
- `Makefile`: For building and running the project

## How to Build and Run

### Main Program

To build and run the main program:

```
make
```

You can also execute these steps individually:

```
make compile
make run
make clean
```

### Tests

To build and run the test suite:

```
make test
```

You can also execute these steps individually:

```
make test_compile
make test_run
make test_clean
```

## Features

The AVL tree implementation includes:

The AVL tree implementation includes:

* Standard BST operations (insertion, deletion, search)
* Self-balancing after each insertion and deletion
* Four rotation types to maintain balance:
    * Left rotation
    * Right rotation
    * Left-Right rotation (double rotation)
    * Right-Left rotation (double rotation)
* Parent pointers for efficient traversal
* Multiple tree traversal methods:
    * In-order traversal (sorted order)
    * Pre-order traversal
    * Post-order traversal
* Height and balance factor calculations

## Main Program

The main program in `main.cpp` generates the first 25 Fibonacci numbers and inserts them into an AVL tree. It then prints the tree using different traversal methods.