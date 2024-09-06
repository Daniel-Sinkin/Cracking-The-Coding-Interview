#include "Constants.h"

namespace helpers {
size_t partition(std::vector<int> &arr, size_t left, size_t right) {
    size_t pivot_idx = left + (right - left) / 2;
    int pivot = arr[pivot_idx];

    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void sort_insertion(vector<int> &arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
} // namespace helpers

void quicksort(std::vector<int> &arr, size_t left, size_t right) {
    const size_t SMALL_ARRAY_THRESHOLD = 16; // If array length below that its faster to use insertion sort

    if (right <= left || right - left < SMALL_ARRAY_THRESHOLD) {
        helpers::sort_insertion(arr, left, right);
        return;
    }

    size_t idx = helpers::partition(arr, left, right);
    if (left < idx - 1) {
        quicksort(arr, left, idx - 1);
    }
    if (idx < right) {
        quicksort(arr, idx, right);
    }
}