#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Constants.h"

void merge_not_inplace(vector<int> &arr1, vector<int> &arr2);

void sort_heap(vector<int> &arr);
void sort_bubble(vector<int> &arr);
vector<int> sort_merge_not_inplace(const vector<int> &arr);

size_t binary_search(const vector<int> &arr, int target);

#endif // ALGORITHMS_H