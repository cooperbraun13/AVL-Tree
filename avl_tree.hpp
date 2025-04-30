#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "avl_node.hpp"
#include <iostream>
#include <functional>

class AVLTree {
    private:
        AVLNode* root;
        int tree_size;

        // Private helper methods
        AVLNode* insert_helper(AVLNode* node, int value, AVLNode* parent);
        AVLNode* delete_helper(AVLNode* node, int value);
        AVLNode* find_min(AVLNode* node);
        AVLNode* find_max(AVLNode* node);

        // Balancing operations
        AVLNode* rotate_left(AVLNode* node);
        AVLNode* rotate_right(AVLNode* node);
        AVLNode* left_right_rotate(AVLNode* node);
        AVLNode* right_left_rotate(AVLNode* node);
        AVLNode* balance(AVLNode* node);

        // Height and balance utilities
        int get_height(AVLNode* node) const;
        int get_balance_factor(AVLNode* node) const;
        void update_height(AVLNode* node);

        // Tree traversal helpers
        void print_in_order_helper(AVLNode* node) const;
        void print_pre_order_helper(AVLNode* node) const;
        void print_post_order_helper(AVLNode* node) const;
        int get_max_height(AVLNode* node) const;

        // Clean up helper
        void delete_subtree(AVLNode* node);

    public:
        // Constructor and destructor
        AVLTree();
        ~AVLTree();

        // BST operations
        bool insert(int value);
        bool remove(int value);
        bool contains(int value) const;

        // Tree property queries
        bool is_empty() const;
        int size() const;
        int height() const;

        // Tree traversal and printing
        void print_in_order() const;
        void print_pre_order() const;
        void print_post_order() const;
};

#endif