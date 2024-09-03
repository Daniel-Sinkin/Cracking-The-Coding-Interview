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
    vector<unique_ptr<BTNode>> children;
}

#endif // DATASTRUCTURES_H