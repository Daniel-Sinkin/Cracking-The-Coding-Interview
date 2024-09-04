#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <aliases.h>

#include <iostream>
#include <memory>
#include <vector>

class LinkedListNode {
public:
    int val;
    unique_ptr<LinkedListNode> next;

    LinkedListNode(int value, unique_ptr<LinkedListNode> nextNode = unique_ptr<LinkedListNode>());
};

class LinkedList {
public:
    unique_ptr<LinkedListNode> root;

    LinkedList(unique_ptr<LinkedListNode> rootNode);

    LinkedListNode &get_tail();
    vector<LinkedListNode *> to_ptr_list();
    vector<int> to_val_list();
    void print_vals();
};

class TreeNode {
public:
    int val;
    vector<unique_ptr<TreeNode>> children;

    TreeNode(int val);
    TreeNode(int val, vector<unique_ptr<TreeNode>> nextNodes);
    void print();
};

class Tree {
public:
    unique_ptr<TreeNode> root;

    Tree(int rootValue);
    Tree(unique_ptr<TreeNode> rootNode);

    void print();
};

/*
Binary Tree
*/
// TODO Implement me
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

/*
BST (Binary Search Tree)
*/
class BSTNode {
private:
    int val;
    unique_ptr<BSTNode> left;
    unique_ptr<BSTNode> right;

public:
    BSTNode(int val);
    BSTNode(int val, unique_ptr<BSTNode> left, unique_ptr<BSTNode> right);
    void insert();

    const BSTNode *get_left() const;
    const BSTNode *get_right() const;
};

class BST {
private:
    unique_ptr<BSTNode> root;

public:
    BST(int val) noexcept;
    BST(unique_ptr<BSTNode> root) noexcept;

    bool is_valid();
    void insert();

    const BSTNode *get_root() const;
};

#endif // DATASTRUCTURES_H