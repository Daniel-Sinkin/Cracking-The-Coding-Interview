#include "binary_search_tree.h"

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
        if (this->left) {
            this->left->insert(new_value);
        } else {
            this->left = make_unique<BSTNode>(new_value);
        }
    } else {
        if (this->right) {
            this->right->insert(new_value);
        } else {
            this->right = make_unique<BSTNode>(new_value);
        }
    }
}

void BSTNode::print_in_order() const {
    if (this->left) {
        this->left->print_in_order();
    }
    fprintf(stdout, " %d ", this->val);
    if (this->right) {
        this->right->print_in_order();
    }
}
void BSTNode::print_pre_order() const {
    fprintf(stdout, " %d ", this->val);
    if (this->left) {
        this->left->print_pre_order();
    }
    if (this->right) {
        this->right->print_pre_order();
    }
}
void BSTNode::print_post_order() const {
    if (this->left) {
        this->left->print_post_order();
    }
    if (this->right) {
        this->right->print_post_order();
    }
    fprintf(stdout, " %d ", this->val);
}

BST::BST(int val) noexcept : root(make_unique<BSTNode>(val)) {};
BST::BST(unique_ptr<BSTNode> root) noexcept : root(std::move(root)) {};

void BST::insert(int new_value) {
    this->root->insert(new_value);
}