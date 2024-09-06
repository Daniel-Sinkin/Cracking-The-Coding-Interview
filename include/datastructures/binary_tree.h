#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Constants.h"

class BTNode {
public:
    int val;
    unique_ptr<BTNode> left;
    unique_ptr<BTNode> right;

    BTNode(int val, unique_ptr<BTNode> left, unique_ptr<BTNode> right);
    BTNode(int val);
};

class BinaryTree {
public:
    unique_ptr<BTNode> root;

    BinaryTree(int val);
    BinaryTree(unique_ptr<BTNode> root);
};

#endif // BINARYTREE_H