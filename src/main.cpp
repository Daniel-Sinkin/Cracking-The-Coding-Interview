#include "algorithms.h"
#include "aliases.h"
#include <iostream>

extern void examples_datastructures();
extern void examples_algorithms();

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Perform merge sort
    vector<int> sorted_arr = sort_merge_not_inplace(arr);

    std::cout << "Sorted array: ";
    for (int num : sorted_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // (void)fprintf(stdout, "\n\nDATASTRUCTURE EXAMPLE\n\n");
    // examples_datastructures();
    // (void)fprintf(stdout, "\n\nALGORITHMS EXAMPLE\n\n");
    // examples_algorithms();
    return 0;
}