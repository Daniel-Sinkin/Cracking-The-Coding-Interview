#include "trie.h"

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