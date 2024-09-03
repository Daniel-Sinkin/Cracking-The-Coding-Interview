#include "datastructures.h"
#include <iostream>
#include <vector>

Node::Node(int value, Node *nextNode) : val(value), next(nextNode) {}

LinkedList::LinkedList(Node *rootNode) : root(rootNode) {}

Node *LinkedList::get_head() {
    Node *curr = this->root;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return curr;
}

std::vector<Node *> LinkedList::to_ptr_list() {
    Node *curr = this->root;
    std::vector<Node *> retval = {this->root};
    while (curr->next != nullptr) {
        retval.push_back(curr->next);
        curr = curr->next;
    }
    return retval;
}

std::vector<int> LinkedList::to_val_list() {
    Node *curr = this->root;
    std::vector<int> retval = {this->root->val};
    while (curr->next != nullptr) {
        retval.push_back(curr->next->val);
        curr = curr->next;
    }
    return retval;
}

void LinkedList::print_vals() {
    Node *curr = this->root;
    while (curr != nullptr) {
        (void)fprintf(stdout, "%d", curr->val);
        curr = curr->next;
        if (curr != nullptr) {
            (void)fprintf(stdout, " -> ");
        }
    }
    (void)fprintf(stdout, "\n");
}