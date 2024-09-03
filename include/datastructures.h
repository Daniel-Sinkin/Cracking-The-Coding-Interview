#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node *next;

    Node(int value, Node *nextNode = nullptr) : val(value), next(nextNode) {}
};

class LinkedList {
public:
    Node *root;

    LinkedList(Node *rootNode);

    Node *get_head();
    std::vector<Node *> to_ptr_list();
    std::vector<int> to_val_list();
    void print_vals();
};

#endif // DATASTRUCTURES_H