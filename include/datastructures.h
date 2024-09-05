#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include "Constants.h"

#include <bitset>
#include <format> // For std::format
#include <iostream>
#include <memory>
#include <stdexcept> // For std::invalid_argument
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
    TrieNode() {
        for (auto &child : this->children) {
            child = nullptr;
        }
        this->is_word = false;
    };

    void insert(string word);
    bool contains_word(string word) const;
    bool contains_prefix(string prefix) const;

    size_t get_char_idx(char chr) const {
        if (chr < 'a' || chr > 'z') {
            throw std::invalid_argument(std::format("Character '{}' not in alphabet (lowercase ascii).", chr));
        }
        return static_cast<size_t>(chr - 'a');
    }
};

class Trie {
private:
    unique_ptr<TrieNode> root;

public:
    Trie() : root(make_unique<TrieNode>()) {}

    void insert(string word) { this->root->insert(word); }
    bool contains_word(string word) const { return this->root->contains_word(word); }
    bool contains_prefix(string prefix) const { return this->root->contains_prefix(prefix); }
};

class MinHeap {
private:
    vector<int> data;

public:
    MinHeap() : data() {}
    void print() const;
    void insert(int value);
    int pop_min();
};

class GraphNode {
private:
    int m_Val;
    vector<GraphNode *> m_Children;

public:
    GraphNode(int value) : m_Val(value) {}

    const vector<GraphNode *> &getChildren() const {
        return m_Children;
    }

    bool addEdge(GraphNode *child) {
        // Returns true if the edge was added, false else (which is the case when the edge already exists)
        for (GraphNode *registered_child : m_Children) {
            if (registered_child == child) {
                return false;
            }
        }
        m_Children.push_back(child);
        return true;
    }

    int getValue() const {
        return m_Val;
    }
};

class Graph {
private:
    vector<GraphNode *> m_Nodes;

public:
    Graph() : m_Nodes() {}

    const vector<GraphNode *> &getNodes() const {
        return m_Nodes;
    }

    const GraphNode *getNode(size_t idx) const {
        return m_Nodes[idx];
    }

    int getValue(size_t node_idx) {
        return m_Nodes[node_idx]->getValue();
    }

    bool addEdge(size_t idx1, size_t idx2) {
        return m_Nodes[idx1]->addEdge(m_Nodes[idx2]);
    }

    GraphNode *createNewNode(int value) {
        GraphNode *newNode = new GraphNode(value);
        m_Nodes.push_back(newNode);
        return newNode;
    }

    bool findBFS(size_t starting_idx, int value_to_find) const;
    bool findDFS(size_t starting_idx, int value_to_find) const;
};

#endif // DATASTRUCTURES_H