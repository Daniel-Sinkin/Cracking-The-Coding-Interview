#ifndef TRIE_H
#define TRIE_H

#include "Constants.h"
#include <format> // For std::format

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

#endif // TRIE_H