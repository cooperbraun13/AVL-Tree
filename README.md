# AVL Tree Implementation

This is an implementation of an AVL Tree, which is a self-balancing binary search tree. After any insertion or deletion operation, the tree automatically maintains balance by ensuring that the height difference between left and right subtrees (balance factor) is at most 1 for all nodes.

## Files Included

- `avl_node.hpp` and `avl_node.cpp`: AVL tree node class
- `avl_tree.hpp` and `avl_tree.cpp`: AVL tree implementation
- `main.cpp`: Inserts the first 25 Fibonacci numbers and prints the tree
- `test_avl_tree.cpp`: Test cases for the AVL tree implementation
- `Makefile`: For building and running the project
- `Specifications.pdf`: Detailed specifications for the features
- `UML_Diagram.pdf`: UML diagram of the classes

## How to Build and Run

### Main Program

To build and run the main program:

```
make
```

This command will:
1. Compile the code using g++
2. Run the executable
3. Clean up the binary file after execution

### Tests

To build and run the tests:

```
make test
```

This command will:
1. Compile the test code using g++
2. Run the test executable
3. Clean up the test binary file after execution

## Features

The AVL tree implementation includes:

- Standard BST operations (insertion, deletion, search)
- Self-balancing after each insertion and deletion
- Four rotation types (left, right, left-right, right-left)
- Parent pointers for efficient traversal
- Multiple tree traversal methods (in-order, pre-order, post-order)

## Main Program

The main program in `main.cpp` generates the first 25 Fibonacci numbers and inserts them into an AVL tree. It then prints the tree using different traversal methods.

## Test Program

The test program in `test_avl_tree.cpp` includes tests for:
- Basic operations (insert, remove, contains)
- Tree properties (is_empty, size)
- Tree balancing for all four rotation cases
- Complex tree balancing with multiple rotations

Each test prints "Passed" or "Failed" based on assertions.