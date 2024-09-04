#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <aliases.h>

#include <bitset>
#include <iostream>
#include <memory>
#include <string>
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

/*
Trie
Only implemented for lowercase ascii alphabet
*/
class TrieNode { // Not to be confused with a TreeNode
private:
    std::array<unique_ptr<TrieNode>, 26> children;
    bool is_word;

public:
    TrieNode();

    void insert(string word);
    bool contains_word(string word) const;
    bool contains_prefix(string prefix) const;
};

class Trie {
public:
    unique_ptr<TrieNode> root;

    Trie();

    void insert(string word);
    bool contains_word(string word) const;
    bool contains_prefix(string prefix) const;
};

/*
Min-Heap
*/
class MinHeapNode {
private:
    int val;
    unique_ptr<MinHeapNode> left;
    unique_ptr<MinHeapNode> right;

public:
    int get_val() const { return this->val; }
    void set_val(int value) { this->val = value; }

    const MinHeapNode *get_left() const { return left.get(); }
    const MinHeapNode *get_right() const { return right.get(); }

    MinHeapNode(int val, unique_ptr<MinHeapNode> left, unique_ptr<MinHeapNode> right)
        : val(val), left(std::move(left)), right(std::move(right)) {}

    MinHeapNode(int val) : val(val) {}
};

class MinHeap {
private:
    unique_ptr<MinHeapNode> root;

public:
    MinHeap(int val) : root(make_unique<MinHeapNode>(val)) {};
    MinHeap(unique_ptr<MinHeapNode> root) : root(std::move(root));
};

#endif // DATASTRUCTURES_H