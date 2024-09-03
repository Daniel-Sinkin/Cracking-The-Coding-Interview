#include "datastructures.h"
#include <iostream>
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

using UP_Node = std::unique_ptr<Node>;
using UP_TreeNode = std::unique_ptr<TreeNode>;

/*
Linked List
*/
Node::Node(int value, UP_Node nextNode)
    : val(value), next(std::move(nextNode)) {}

LinkedList::LinkedList(UP_Node rootNode)
    : root(std::move(rootNode)) {}

Node &LinkedList::get_tail() {
    Node *curr = this->root.get();
    while (curr->next != nullptr) {
        curr = curr->next.get();
    }
    return *curr;
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

TreeNode::TreeNode(int value, vector<UP_TreeNode> nextNodes)
    : val(value), children(std::move(nextNodes)) {}

void TreeNode::print() {
    (void)fprintf(stdout, "%d", this->val);
    for (auto &x : this->children) {
        x->print();
    }
}

Tree::Tree(int rootValue)
    : root(make_unique<TreeNode>(rootValue)) {}

Tree::Tree(unique_ptr<TreeNode> rootNode)
    : root(std::move(rootNode)) {}

void Tree::print() {
    if (root) {
        this->root->print();
    }
}