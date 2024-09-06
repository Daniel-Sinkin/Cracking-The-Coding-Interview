#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H
#include "Constants.h"

void heapsort(vector<int> &arr);
void bubblesort(vector<int> &arr);
void quicksort(vector<int> &arr, size_t left, size_t right);
vector<int> sort_merge_not_inplace(const vector<int> &arr);

#endif // ALGORITHMS_SORTING_H