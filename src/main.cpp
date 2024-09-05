#include "aliases.h"
#include "datastructures.h"

extern void run_all_examples();

void minheap_print(const vector<int> &minheap) {
    size_t layer = 0;
    size_t exponented = 2;

    const size_t size = minheap.size();
    fprintf(stdout, "0. Layer: %d\n", minheap[0]);
    bool is_running = true;
    while (is_running) {
        for (size_t idx = exponented - 1; idx < 2 * exponented - 1; idx++) {
            if (idx >= size) {
                is_running = false;
                break;
            }
            (void)fprintf(stdout, "%zu. Layer: 2^%zu + %zu = %d\n", layer + 1, layer, idx, minheap[idx]);
        }
        exponented *= 2;
        layer += 1;
    }
}

void minheap_insert(vector<int> &minheap, int value) {
    // Put new value at the end
    minheap.push_back(value);
    // get index of new node
    size_t current_idx = minheap.size() - 1;

    while (current_idx > 0) { // Until we reach the root
        // For the parent determination, suppose we consider 14, obviously
        // 8 <= 14 < 16, so it is in the 4. layer (root being 1.), because
        // it satisfies 2^(i - 1) - 1 <= x < 2^i - 1 for i = 4.
        // The layer above that one consists of
        // 3, 4, 5, 6
        // which correspond to
        // [7, 8], [9, 10], [11, 12], [13, 14]
        // in the lowest layer with the map 2j + k, k in {1, 2} so we can
        // recover j with floor(((2j + k) - 1) / 2).
        // Sidenode, ofcourse k = 1 denotes left child, k = 2 the right child
        size_t parent_idx = (current_idx - 1) / 2;
        // If we reach a node that preserves the heap property locally then
        // the entire tree is a heap.
        if (minheap[current_idx] < minheap[parent_idx]) {
            std::swap(minheap[current_idx], minheap[parent_idx]);
            current_idx = parent_idx;
        } else {
            break;
        }
    }
}

void minheap_remove_min(vector<int> &minheap) {
    // If we have no elements we can't remove anything.
    if (minheap.empty()) {
        return;
    }

    // Idea is that we "swap" the last entry with the root and then remove the node at the end,
    // but the swapping itself is wasted work.
    // We have achied our goal we have either reached the end (current_index == size)
    // or if we don't change anything in the swapping stages (parent is not bigger than its children)
    size_t current_idx = 0;
    const size_t size = minheap.size();

    while (current_idx < size) {
        size_t smallest_idx = current_idx;

        size_t left_child_idx = 2 * current_idx + 1;
        bool left_child_exists = left_child_idx < size;

        size_t right_child_idx = 2 * current_idx + 2;
        bool right_child_exists = right_child_idx < size;

        // Check if we want to swap parent with left_child_value
        if (left_child_exists && minheap[left_child_idx] < minheap[smallest_idx]) {
            smallest_idx = left_child_idx;
        }
        // Check if we want to swap min(parent, left_child_value) with right_child_value
        if (right_child_exists && minheap[right_child_idx] < minheap[smallest_idx]) {
            smallest_idx = right_child_idx;
        }
        if (smallest_idx == current_idx) {
            break;
        }

        std::swap(minheap[current_idx], minheap[smallest_idx]);
        current_idx = smallest_idx;
    }
}

int main() {
    // run_all_examples();

    vector<int> minheap = {4, 50, 7, 55, 90, 87};
    minheap_print(minheap);

    minheap_insert(minheap, 2);
    minheap_print(minheap);

    minheap_insert(minheap, 3);
    minheap_print(minheap);

    minheap_insert(minheap, 4);
    minheap_print(minheap);

    return 0;
}