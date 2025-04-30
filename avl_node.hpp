#ifndef AVL_NODE_HPP
#define AVL_TREE_HPP

class AVLNode {
    public:
        int value;
        AVLNode* left;
        AVLNode* right;
        AVLNode* parent;
        int height;
        AVLNode(int val);
        ~AVLNode();
};

#endif