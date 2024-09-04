#include "datastructures.h"
#include "aliases.h"
#include <iostream>
#include <memory>
#include <vector>

/*
Linked List
*/
LinkedListNode::LinkedListNode(int value, unique_ptr<LinkedListNode> nextNode)
    : val(value), next(std::move(nextNode)) {}

LinkedList::LinkedList(unique_ptr<LinkedListNode> rootNode)
    : root(std::move(rootNode)) {}

LinkedListNode &LinkedList::get_tail() {
    LinkedListNode *curr = this->root.get();
    while (curr->next != nullptr) {
        curr = curr->next.get();
    }
    return *curr;
}

vector<LinkedListNode *> LinkedList::to_ptr_list() {
    vector<LinkedListNode *> retval;
    LinkedListNode *curr = this->root.get();
    while (curr != nullptr) {
        retval.push_back(curr);
        curr = curr->next.get();
    }
    return retval;
}

vector<int> LinkedList::to_val_list() {
    vector<int> retval;
    LinkedListNode *curr = this->root.get();
    while (curr != nullptr) {
        retval.push_back(curr->val);
        curr = curr->next.get();
    }
    return retval;
}

void LinkedList::print_vals() {
    LinkedListNode *curr = this->root.get();
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

Tree::Tree(int rootValue)
    : root(make_unique<TreeNode>(rootValue)) {}

Tree::Tree(unique_ptr<TreeNode> root)
    : root(std::move(root)) {}

void Tree::print() {
    if (root) {
        this->root->print();
    }
}

/*
BinaryTree
*/
BTNode::BTNode(
    int val,
    unique_ptr<BTNode> left,
    unique_ptr<BTNode> right)
    : val(val),
      left(std::move(left)),
      right(std::move(right)) {}

BTNode::BTNode(int val) : val(val) {}

BinaryTree::BinaryTree(int val) : root(make_unique<BTNode>(val)) {}
BinaryTree::BinaryTree(unique_ptr<BTNode> root) : root(std::move(root)) {}

/*
BST (Binary Search Tree)
*/
BSTNode::BSTNode(int val, unique_ptr<BSTNode> left, unique_ptr<BSTNode> right) : val(val), left(std::move(left)), right(std::move(right)) {}
BSTNode::BSTNode(int val) : val(val) {}

const BSTNode *BSTNode::get_left() const {
    return this->left.get();
};

const BSTNode *BSTNode::get_right() const {
    return this->right.get();
};

const BSTNode *BST::get_root() const {
    return this->root.get();
}

void BSTNode::insert(int new_value) {
    if (new_value <= this->val) {
        if (this->left != nullptr) {
            this->left->insert(new_value);
        } else {
            this->left = make_unique<BSTNode>(new_value);
        }
    } else {
        if (this->right != nullptr) {
            this->right->insert(new_value);
        } else {
            this->right = make_unique<BSTNode>(new_value);
        }
    }
}

void BSTNode::print_in_order() const {
    if (this->left != nullptr) {
        this->left->print_in_order();
    }
    (void)fprintf(stdout, " %d ", this->val);
    if (this->right != nullptr) {
        this->right->print_in_order();
    }
}
void BSTNode::print_pre_order() const {
    (void)fprintf(stdout, " %d ", this->val);
    if (this->left != nullptr) {
        this->left->print_pre_order();
    }
    if (this->right != nullptr) {
        this->right->print_pre_order();
    }
}
void BSTNode::print_post_order() const {
    if (this->left != nullptr) {
        this->left->print_post_order();
    }
    if (this->right != nullptr) {
        this->right->print_post_order();
    }
    (void)fprintf(stdout, " %d ", this->val);
}

BST::BST(int val) noexcept : root(make_unique<BSTNode>(val)) {};
BST::BST(unique_ptr<BSTNode> root) noexcept : root(std::move(root)) {};

void BST::insert(int new_value) {
    this->root->insert(new_value);
}