#include "aliases.h"
#include "datastructures.h"

void sort_heap(vector<int> &arr) {
    MinHeap heap;
    for (int val : arr) {
        heap.insert(val);
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = heap.pop_min();
    }
}

void sort_bubble(vector<int> &arr) {
    for (size_t outer = 0; outer < arr.size() - 1; outer++) {
        for (size_t inner = 0; inner < arr.size() - 1 - outer; inner++) {
            if (arr[inner] > arr[inner + 1]) {
                std::swap(arr[inner], arr[inner + 1]);
            }
        }
    }
}