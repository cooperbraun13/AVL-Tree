#include "avl_tree.hpp"
#include <algorithm>

// Constructor
AVLTree::AVLTree() : root(nullptr), tree_size(0) {}

// Destructor
AVLTree::~AVLTree() {
    delete_subtree(root);
}

// Helper to delete entire subtree recursively
void AVLTree::delete_subtree(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    
    // Post order traversal deletion
    delete_subtree(node->left);
    delete_subtree(node->right);
    delete node;
}

// Height and balance utilities
int AVLTree::get_height(AVLNode* node) const {
    if (node == nullptr) return 0;
    return node->height;
}

void AVLTree::update_height(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));
}

int AVLTree::get_balance_factor(AVLNode* node) const {
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
}