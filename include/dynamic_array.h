#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Constants.h"

class DynamicArray {
private:
    int *m_DataPtr;
    size_t m_Size;
    size_t m_Capacity;

public:
    DynamicArray();
    ~DynamicArray();

    int get(size_t idx) const;
    void set(size_t idx, int val);
    size_t get_size() const;
    size_t get_capacity() const;
    void push_back(int val);
    int get_back() const;
    int pop_back();
    void insert(size_t idx, int val);
    void remove(size_t idx);
};
#endif // DYNAMICARRAY_H