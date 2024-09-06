#include "datastructures.h"
#include "Constants.h"

#include <iostream>
#include <memory>
#include <string>
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
    while (curr->next) {
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
    (void)fprintf(stdout, " %d ", this->val);
    if (this->right) {
        this->right->print_in_order();
    }
}
void BSTNode::print_pre_order() const {
    (void)fprintf(stdout, " %d ", this->val);
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
    (void)fprintf(stdout, " %d ", this->val);
}

BST::BST(int val) noexcept : root(make_unique<BSTNode>(val)) {};
BST::BST(unique_ptr<BSTNode> root) noexcept : root(std::move(root)) {};

void BST::insert(int new_value) {
    this->root->insert(new_value);
}

/*
Trie
*/
void TrieNode::insert(string word) {
    if (word.empty()) {
        return;
    }

    size_t char_idx = get_char_idx(word[0]);
    if (!this->children[char_idx]) {
        this->children[char_idx] = make_unique<TrieNode>();
    }
    if (word.length() == 1) {
        this->children[char_idx]->is_word = true;
    } else {
        this->children[char_idx]->insert(word.substr(1));
    }
}

bool TrieNode::contains_word(string word) const {
    if (word.empty()) {
        return this->is_word;
    }

    size_t char_idx = this->get_char_idx(word[0]);
    if (this->children[char_idx]) {
        return this->children[char_idx]->contains_word(word.substr(1));
    }

    return false;
}

bool TrieNode::contains_prefix(string prefix) const {
    if (prefix.empty()) {
        return true;
    }
    size_t char_idx = this->get_char_idx(prefix[0]);
    if (this->children[char_idx]) {
        return this->children[char_idx]->contains_prefix(prefix.substr(1));
    }
    return false;
}

/*
MinHeap
*/
void MinHeap::print() const {
    size_t layer = 0;
    size_t exponented = 2;

    const size_t size = this->data.size();
    (void)fprintf(stdout, "0. Layer: %d\n", this->data[0]);
    bool is_running = true;
    while (is_running) {
        for (size_t idx = exponented - 1; idx < 2 * exponented - 1; idx++) {
            if (idx >= size) {
                is_running = false;
                break;
            }
            (void)fprintf(stdout, "%zu. Layer: 2^%zu + %zu = %d\n", layer + 1, layer, idx, this->data[idx]);
        }
        exponented *= 2;
        layer += 1;
    }
}

/*
For the parent determination, suppose we consider 14, obviously
    8 <= 14 < 16,
so it is in the 4. layer (root being 1.), because it satisfies
    2^(i - 1) - 1 <= x < 2^i - 1
for i = 4. The layer above that one consists of
    3, 4, 5, 6
which correspond to
    [7, 8], [9, 10], [11, 12], [13, 14]
in the lowest layer with the map
    2j + k, k in {1, 2}
so we can recover j with
    floor(((2j + k) - 1) / 2).
Sidenode: k=1 selects the left child, k = 2 the right child
*/
void MinHeap::insert(int value) {
    // Put new value at the end
    this->data.push_back(value);
    // get index of new node
    size_t current_idx = this->data.size() - 1;

    while (current_idx > 0) { // Until we reach the root

        size_t parent_idx = (current_idx - 1) / 2;
        // If we reach a node that preserves the heap property locally then
        // the entire tree is a heap.
        if (this->data[current_idx] < this->data[parent_idx]) {
            std::swap(this->data[current_idx], this->data[parent_idx]);
            current_idx = parent_idx;
        } else {
            break;
        }
    }
}

int MinHeap::pop_min() {
    // If we have no elements we can't remove anything.
    if (this->data.empty()) {
        throw std::runtime_error("Cannot invoke pop_min on an empty MinHeap.");
    }

    // Idea is that we "swap" the last entry with the root and then remove the node at the end,
    // but the swapping itself is wasted work.
    int min_value = this->data[0];
    this->data[0] = this->data.back();
    this->data.pop_back();

    // We have achied our goal we have either reached the end (current_index == size)
    // or if we don't change anything in the swapping stages (parent is not bigger than its children)
    size_t current_idx = 0;
    const size_t size = this->data.size();

    while (current_idx < size) {
        size_t smallest_idx = current_idx;

        size_t left_child_idx = 2 * current_idx + 1;
        bool left_child_exists = left_child_idx < size;

        size_t right_child_idx = 2 * current_idx + 2;
        bool right_child_exists = right_child_idx < size;

        // Check if we want to swap parent with left_child_value
        if (left_child_exists && this->data[left_child_idx] < this->data[smallest_idx]) {
            smallest_idx = left_child_idx;
        }
        // Check if we want to swap min(parent, left_child_value) with right_child_value
        if (right_child_exists && this->data[right_child_idx] < this->data[smallest_idx]) {
            smallest_idx = right_child_idx;
        }
        if (smallest_idx == current_idx) {
            break;
        }

        std::swap(this->data[current_idx], this->data[smallest_idx]);
        current_idx = smallest_idx;
    }
    return min_value;
}

/*
Graph
*/
bool Graph::findBFS(size_t starting_idx, int value_to_find) const {
    unordered_set<const GraphNode *> seen_nodes;
    queue<const GraphNode *> nodes_to_visit;

    const GraphNode *first_node = this->getNode(starting_idx);
    nodes_to_visit.push(first_node);
    seen_nodes.insert(first_node);

    while (!nodes_to_visit.empty()) {
        const GraphNode *current_node = nodes_to_visit.front();
        nodes_to_visit.pop();

        if (current_node->getValue() == value_to_find) {
            return true;
        }

        for (GraphNode *const &child : current_node->getChildren()) {
            bool child_was_seen = seen_nodes.find(child) != seen_nodes.end();
            if (!child_was_seen) {
                seen_nodes.insert(child);

                nodes_to_visit.push(child);
            }
        }
    }
    return false;
}

bool Graph::findDFS(size_t starting_idx, int value_to_find) const {
    unordered_set<const GraphNode *> seen_nodes;

    stack<const GraphNode *> nodes_to_visit;

    const GraphNode *starting_node = getNode(starting_idx);
    nodes_to_visit.push(starting_node);
    seen_nodes.insert(starting_node);

    while (!nodes_to_visit.empty()) {
        const GraphNode *current_node = nodes_to_visit.top();
        nodes_to_visit.pop();

        if (current_node->getValue() == value_to_find) {
            return true;
        }

        for (GraphNode *const &child : current_node->getChildren()) {
            bool child_not_seen = seen_nodes.find(child) == seen_nodes.end();
            if (child_not_seen) {
                seen_nodes.insert(child);
                nodes_to_visit.push(child);
            }
        }
    }
    return false;
}

/*
DynamicArray
*/
DynamicArray::DynamicArray() {
    m_Size = 0;
    m_Capacity = 8;
    (void)fprintf(stdout, "Initializing DynamicArray with capacity %zu\n", m_Capacity);
    // Using new and delete instead of malloc and free would be better, but this is more barebones
    // Using static_cast<int*>(...) is generally better than (int *) but doesn't matter here.
    m_DataPtr = (int *)malloc(m_Capacity * sizeof(int));
    if (m_DataPtr == nullptr) {
        (void)fprintf(stderr, "Failed to do initial malloc call!\n");
        throw std::runtime_error("Failed to do initial malloc call!");
    }
}

DynamicArray::~DynamicArray() {
    (void)fprintf(stdout, "Destroying DynamicArray, freeing memory\n");
    free(m_DataPtr);
}

int DynamicArray::get(size_t idx) const {
    (void)fprintf(stdout, "Trying to get value at index %zu\n", idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Index %zu out of bounds! Array size is %zu\n", idx, m_Size);
        throw std::out_of_range("Index out of bounds!");
    }
    return *(m_DataPtr + idx);
}

void DynamicArray::set(size_t idx, int val) {
    (void)fprintf(stdout, "Trying to set value %d at index %zu\n", val, idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Index %zu out of bounds! Array size is %zu\n", idx, m_Size);
        throw std::out_of_range("Index out of bounds!");
    }
    *(m_DataPtr + idx) = val;
}

size_t DynamicArray::get_size() const {
    (void)fprintf(stdout, "Getting current size: %zu\n", m_Size);
    return m_Size;
}

size_t DynamicArray::get_capacity() const {
    (void)fprintf(stdout, "Getting current capacity: %zu\n", m_Capacity);
    return m_Capacity;
}

void DynamicArray::push_back(int val) {
    (void)fprintf(stdout, "Pushing back value %d\n", val);
    if (m_Size >= m_Capacity) {
        size_t new_capacity = 2 * m_Capacity;
        (void)fprintf(stdout, "Capacity reached, reallocating to new capacity %zu\n", new_capacity);
        int *realloc_ptr = (int *)realloc(m_DataPtr, new_capacity * sizeof(int));
        if (realloc_ptr == nullptr) {
            (void)fprintf(stderr, "Failed to reallocate memory!\n");
            throw std::runtime_error("Failed to reallocate!");
        }
        m_DataPtr = realloc_ptr;
        m_Capacity = new_capacity;
    }
    m_Size += 1;
    set(m_Size - 1, val);
    (void)fprintf(stdout, "New size after push_back: %zu\n", m_Size);
}

int DynamicArray::get_back() const {
    (void)fprintf(stdout, "Getting last element\n");
    if (m_Size == 0) {
        (void)fprintf(stderr, "Attempted to get_back on empty DynamicArray!\n");
        throw std::runtime_error("Invoked get_back on empty DynamicArray!");
    }
    return get(m_Size - 1);
}

int DynamicArray::pop_back() {
    (void)fprintf(stdout, "Popping last element\n");
    if (m_Size == 0) {
        (void)fprintf(stderr, "Attempted to pop_back on empty DynamicArray!\n");
        throw std::runtime_error("Invoked pop_back on empty DynamicArray!");
    }
    int last_element = get(m_Size - 1);
    m_Size -= 1;
    (void)fprintf(stdout, "New size after pop_back: %zu\n", m_Size);
    return last_element;
}

void DynamicArray::insert(size_t idx, int val) {
    (void)fprintf(stdout, "Attempting to insert value %d at index %zu\n", val, idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Attempted to insert at index %zu which is >= size %zu on DynamicArray!\n", idx, m_Size);
        throw std::runtime_error("Attempted to insert at index that is >= size on DynamicArray!");
    }

    (void)fprintf(stdout, "Shifting elements to make room for insertion\n");
    int last_element = get_back();
    for (size_t i = m_Size - 1; i > idx; i--) {
        (void)fprintf(stdout, "Moving element from index %zu to %zu\n", i - 1, i);
        set(i, get(i - 1));
    }

    (void)fprintf(stdout, "Inserting value %d at index %zu\n", val, idx);
    set(idx, val);

    (void)fprintf(stdout, "Pushing back last element %d to accommodate insertion\n", last_element);
    push_back(last_element);

    (void)fprintf(stdout, "Insertion complete. New size: %zu\n", m_Size);
}

void DynamicArray::remove(size_t idx) {
    (void)fprintf(stdout, "Attempting to remove element at index %zu\n", idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Attempted to remove at index %zu which is >= size %zu on DynamicArray!\n", idx, m_Size);
        throw std::runtime_error("Attempted to remove at index that is >= size on DynamicArray!");
    }

    (void)fprintf(stdout, "Shifting elements to fill the gap after removal\n");
    for (size_t i = idx; i < m_Size - 1; i++) {
        (void)fprintf(stdout, "Moving element from index %zu to %zu\n", i + 1, i);
        set(i, get(i + 1));
    }

    m_Size -= 1;
    (void)fprintf(stdout, "Removal complete. New size: %zu\n", m_Size);
}