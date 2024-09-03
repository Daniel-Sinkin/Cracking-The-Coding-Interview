#include "datastructures.h"
#include <iostream>
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

/*
Linked List
*/
Node::Node(int value, unique_ptr<Node> nextNode)
    : val(value), next(std::move(nextNode)) {}

LinkedList::LinkedList(unique_ptr<Node> rootNode)
    : root(std::move(rootNode)) {}

Node *LinkedList::get_tail() {
    Node *curr = this->root.get();
    while (curr->next != nullptr) {
        curr = curr->next.get();
    }
    return curr;
}

vector<Node *> LinkedList::to_ptr_list() {
    vector<Node *> retval;
    Node *curr = this->root.get();
    while (curr != nullptr) {
        retval.push_back(curr);
        curr = curr->next.get();
    }
    return retval;
}

vector<int> LinkedList::to_val_list() {
    vector<int> retval;
    Node *curr = this->root.get();
    while (curr != nullptr) {
        retval.push_back(curr->val);
        curr = curr->next.get();
    }
    return retval;
}

void LinkedList::print_vals() {
    Node *curr = this->root.get();
    while (curr != nullptr) {
        (void)fprintf(stdout, "%d", curr->val);
        curr = curr->next.get();
        if (curr != nullptr) {
            (void)fprintf(stdout, " -> ");
        }
    }
    (void)fprintf(stdout, "\n");
}

/*
Tree
*/
TreeNode::TreeNode(int value)
    : val(value) {}

TreeNode::TreeNode(int value, vector<unique_ptr<TreeNode>> nextNodes)
    : val(value), children(std::move(nextNodes)) {}

void TreeNode::print() {
    (void)fprintf(stdout, "%d", this->val);
    for (auto &x : this->children) {
        x->print();
    }
}

void Tree::print() {
    this->root.print();
}