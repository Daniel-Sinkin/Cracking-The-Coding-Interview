#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Constants.h"

class BSTNode {
private:
    int val;
    unique_ptr<BSTNode> left;
    unique_ptr<BSTNode> right;

public:
    BSTNode(int val);
    BSTNode(int val, unique_ptr<BSTNode> left, unique_ptr<BSTNode> right);
    void insert(int new_value);

    const BSTNode *get_left() const;
    const BSTNode *get_right() const;

    void print_in_order() const;
    void print_pre_order() const;
    void print_post_order() const;
};

class BST {
private:
    unique_ptr<BSTNode> root;

public:
    BST(int val) noexcept;
    BST(unique_ptr<BSTNode> root) noexcept;

    void insert(int new_value);

    const BSTNode *get_root() const;
};

#endif // BINARYSEARCHTREE_H