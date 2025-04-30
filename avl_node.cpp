#include "avl_node.hpp"

AVLNode::AVLNode(int val) :
    value(val), // Node's value
    left(nullptr), // Left child pointer
    right(nullptr), // Right child pointer
    parent(nullptr), // Parent pointer
    height(1) // Height starts at 1
{

}

// Node destructor
AVLNode::~AVLNode() {

}