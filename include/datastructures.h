#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

class Node {
public:
    int val;
    unique_ptr<Node> next;

    Node(int value, unique_ptr<Node> nextNode = unique_ptr<Node>());
};

class LinkedList {
public:
    unique_ptr<Node> root;

    LinkedList(unique_ptr<Node> rootNode);

    Node &get_tail();
    vector<Node *> to_ptr_list();
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
    unique_ptr<TreeNode> root; // Make root a unique_ptr to allow proper memory management

    Tree(int rootValue);                 // Constructor to initialize the root with a value
    Tree(unique_ptr<TreeNode> rootNode); // Constructor to initialize the tree with an existing TreeNode

    void print();
};

#endif // DATASTRUCTURES_H