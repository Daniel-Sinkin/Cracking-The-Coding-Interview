#ifndef MINHEAP_H
#define MINHEAP_H

#include "Constants.h"

class MinHeap {
private:
    vector<int> data;

public:
    MinHeap() : data() {}
    void print() const;
    void insert(int value);
    int pop_min();
};

#endif // MINHEAP_H