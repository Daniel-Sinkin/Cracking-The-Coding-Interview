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
