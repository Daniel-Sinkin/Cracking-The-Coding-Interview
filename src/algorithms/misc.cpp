#include "Constants.h"

size_t binary_search(const std::vector<int> &arr, int target) {
    const size_t TARGET_NOT_FOUND = arr.size();

    if (arr.empty()) {
        return TARGET_NOT_FOUND;
    }

    size_t left = 0;
    size_t right = arr.size() - 1;

    while (left <= right) {
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
