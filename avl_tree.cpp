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

// Rotation operations
AVLNode* AVLTree::rotate_left(AVLNode* node) {
    AVLNode* new_root = node->right;
    AVLNode* subtree = new_root->left;
    
    // Perform rotation
    new_root->left = node;
    node->right = subtree;
    
    // Update parent pointers
    new_root->parent = node->parent;
    node->parent = new_root;
    if (subtree != nullptr) {
        subtree->parent = node;
    }
    
    // Update heights
    update_height(node);
    update_height(new_root);
    
    return new_root;
}

AVLNode* AVLTree::rotate_right(AVLNode* node) {
    AVLNode* new_root = node->left;
    AVLNode* subtree = new_root->right;
    
    // Perform rotation
    new_root->right = node;
    node->left = subtree;
    
    // Update parent pointers
    new_root->parent = node->parent;
    node->parent = new_root;
    if (subtree != nullptr) {
        subtree->parent = node;
    }
    
    // Update heights
    update_height(node);
    update_height(new_root);
    
    return new_root;
}

AVLNode* AVLTree::left_right_rotate(AVLNode* node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
}

AVLNode* AVLTree::right_left_rotate(AVLNode* node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
}

AVLNode* AVLTree::balance(AVLNode* node) {
    if (node == nullptr) return nullptr;
    
    // Update height
    update_height(node);
    
    // Get balance factor
    int balance_factor = get_balance_factor(node);
    
    // Left heavy
    if (balance_factor > 1) {
        // Left Left case
        if (get_balance_factor(node->left) >= 0) {
            return rotate_right(node);
        }
        // Left Right case
        else {
            return left_right_rotate(node);
        }
    }
    // Right heavy
    else if (balance_factor < -1) {
        // Right Right case
        if (get_balance_factor(node->right) <= 0) {
            return rotate_left(node);
        }
        // Right Left case
        else {
            return right_left_rotate(node);
        }
    }
    
    // No balancing needed
    return node;
}

// Insert operation
bool AVLTree::insert(int value) {
    // Check if value already exists in the tree
    if (contains(value)) {
        return false;
    }
    
    root = insert_helper(root, value, nullptr);
    tree_size++;
    return true;
}

AVLNode* AVLTree::insert_helper(AVLNode* node, int value, AVLNode* parent) {
    // Base case, found the position to insert
    if (node == nullptr) {
        AVLNode* new_node = new AVLNode(value);
        new_node->parent = parent;
        return new_node;
    }
    
    // Recursive case, traverse to find insertion point
    if (value < node->value) {
        node->left = insert_helper(node->left, value, node);
    } else if (value > node->value) {
        node->right = insert_helper(node->right, value, node);
    } else {
        // Value already exists
        return node;
    }
    
    // Balance the tree after insertion
    return balance(node);
}

// Find minimum node in a subtree
AVLNode* AVLTree::find_min(AVLNode* node) {
    if (node == nullptr) return nullptr;
    
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Find maximum node in a subtree
AVLNode* AVLTree::find_max(AVLNode* node) {
    if (node == nullptr) return nullptr;
    
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Remove operation
bool AVLTree::remove(int value) {
    // Check if tree is empty or value doesn't exist
    if (is_empty() || !contains(value)) {
        return false;
    }
    
    root = delete_helper(root, value);
    tree_size--;
    return true;
}

AVLNode* AVLTree::delete_helper(AVLNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    
    // Search for the node to delete
    if (value < node->value) {
        node->left = delete_helper(node->left, value);
        if (node->left != nullptr) {
            node->left->parent = node;
        }
    } else if (value > node->value) {
        node->right = delete_helper(node->right, value);
        if (node->right != nullptr) {
            node->right->parent = node;
        }
    } else {
        // Node with no children or one child
        if (node->left == nullptr) {
            AVLNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            AVLNode* temp = node->left;
            delete node;
            return temp;
        }
        
        // Node with two children, find the inorder successor
        AVLNode* successor = find_min(node->right);
        
        // Copy the successor's value to this node
        node->value = successor->value;
        
        // Delete the successor
        node->right = delete_helper(node->right, successor->value);
        if (node->right != nullptr) {
            node->right->parent = node;
        }
    }
    
    // Balance the tree after deletion
    return balance(node);
}

// Contains operation
bool AVLTree::contains(int value) const {
    AVLNode* current = root;
    
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } else if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return false;
}

// Tree property queries
bool AVLTree::is_empty() const {
    return root == nullptr;
}

int AVLTree::size() const {
    return tree_size;
}

int AVLTree::height() const {
    return get_max_height(root);
}

int AVLTree::get_max_height(AVLNode* node) const {
    if (node == nullptr) return 0;
    return node->height;
}

// Tree traversal functions
void AVLTree::print_in_order() const {
    print_in_order_helper(root);
    std::cout << std::endl;
}

void AVLTree::print_in_order_helper(AVLNode* node) const {
    if (node == nullptr) return;
    
    print_in_order_helper(node->left);
    std::cout << node->value << " ";
    print_in_order_helper(node->right);
}

void AVLTree::print_pre_order() const {
    print_pre_order_helper(root);
    std::cout << std::endl;
}

void AVLTree::print_pre_order_helper(AVLNode* node) const {
    if (node == nullptr) return;
    
    std::cout << node->value << " ";
    print_pre_order_helper(node->left);
    print_pre_order_helper(node->right);
}

void AVLTree::print_post_order() const {
    print_post_order_helper(root);
    std::cout << std::endl;
}

void AVLTree::print_post_order_helper(AVLNode* node) const {
    if (node == nullptr) return;
    
    print_post_order_helper(node->left);
    print_post_order_helper(node->right);
    std::cout << node->value << " ";
}