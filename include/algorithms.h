#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <aliases.h>

void merge_not_inplace(vector<int> &arr1, vector<int> &arr2);

void sort_heap(vector<int> &arr);
void sort_bubble(vector<int> &arr);
vector<int> sort_merge_not_inplace(const vector<int> &arr);

#endif // ALGORITHMS_H