#include "Constants.h"

#include "min_heap.h"

void heapsort(vector<int> &arr) {
    MinHeap heap;
    for (int val : arr) {
        heap.insert(val);
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = heap.pop_min();
    }
}

void bubblesort(vector<int> &arr) {
    for (size_t outer = 0; outer < arr.size() - 1; outer++) {
        for (size_t inner = 0; inner < arr.size() - 1 - outer; inner++) {
            if (arr[inner] > arr[inner + 1]) {
                std::swap(arr[inner], arr[inner + 1]);
            }
        }
    }
}

namespace mergesort_helpers {
vector<int> merge(const vector<int> &arr1, const vector<int> &arr2) {
    // Note that this is the BAD version of the merge helper function as it
    // allocates new memory, the GOOD basic version is doing everything inplace
    // on the original array.
    const size_t size1 = arr1.size();
    const size_t size2 = arr2.size();

    vector<int> arr_merged;
    arr_merged.reserve(size1 + size2);

    size_t left = 0;
    size_t right = 0;

    while ((left < size1) and (right < size2)) {
        if (arr1[left] < arr2[right]) {
            arr_merged.push_back(arr1[left]);
            left += 1;
        } else {
            arr_merged.push_back(arr2[right]);
            right += 1;
        }
    }
    if (left == size1) {
        while (right < size2) {
            arr_merged.push_back(arr2[right]);
            right += 1;
        }
    }
    if (right == size2) {
        while (left < size1) {
            arr_merged.push_back(arr1[left]);
            left += 1;
        }
    }
    return arr_merged;
}
} // namespace mergesort_helpers

vector<int> sort_merge_not_inplace(const vector<int> &arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = static_cast<int>(arr.size()) / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = sort_merge_not_inplace(left);
    right = sort_merge_not_inplace(right);

    return mergesort_helpers::merge(left, right);
}

namespace quicksort_helpers {
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
} // namespace quicksort_helpers

void quicksort(std::vector<int> &arr, size_t left, size_t right) {
    const size_t SMALL_ARRAY_THRESHOLD = 16; // If array length below that its faster to use insertion sort

    if (right <= left || right - left < SMALL_ARRAY_THRESHOLD) {
        quicksort_helpers::sort_insertion(arr, left, right);
        return;
    }

    size_t idx = quicksort_helpers::partition(arr, left, right);
    if (left < idx - 1) {
        quicksort(arr, left, idx - 1);
    }
    if (idx < right) {
        quicksort(arr, idx, right);
    }
}