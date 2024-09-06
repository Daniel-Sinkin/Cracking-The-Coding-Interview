#include "Constants.h"

#include "min_heap.h"

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

vector<int> merge_not_inplace(const vector<int> &arr1, const vector<int> &arr2) {
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

vector<int> sort_merge_not_inplace(const vector<int> &arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = static_cast<int>(arr.size()) / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = sort_merge_not_inplace(left);
    right = sort_merge_not_inplace(right);

    return merge_not_inplace(left, right);
}

size_t binary_search(const std::vector<int> &arr, int target) {
    const size_t TARGET_NOT_FOUND = arr.size();

    if (arr.empty()) {
        return TARGET_NOT_FOUND;
    }

    size_t left = 0;
    size_t right = arr.size() - 1;

    while (left <= right) {
        // This makes taking average more stable against integer overflow as right >= left is guaranteed
        // Interesting read regarding assembly optimizations of averaging ints:
        // https://devblogs.microsoft.com/oldnewthing/20220207-00/?p=106223
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0) {
                break;
            }
            right = mid - 1;
        }
    }

    return TARGET_NOT_FOUND;
}