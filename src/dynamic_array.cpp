#include "dynamic_array.h"

DynamicArray::DynamicArray() {
    m_Size = 0;
    m_Capacity = 8;
    (void)fprintf(stdout, "Initializing DynamicArray with capacity %zu\n", m_Capacity);
    // Using new and delete instead of malloc and free would be better
    // Using static_cast<int*>(...) instead of C-style casting (int *)(...) would be better
    m_DataPtr = (int *)malloc(m_Capacity * sizeof(int));
    if (m_DataPtr == nullptr) {
        (void)fprintf(stderr, "Failed to do initial malloc call!\n");
        throw std::runtime_error("Failed to do initial malloc call!");
    }
}

DynamicArray::~DynamicArray() {
    (void)fprintf(stdout, "Destroying DynamicArray, freeing memory\n");
    free(m_DataPtr);
}

int DynamicArray::get(size_t idx) const {
    (void)fprintf(stdout, "Trying to get value at index %zu\n", idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Index %zu out of bounds! Array size is %zu\n", idx, m_Size);
        throw std::out_of_range("Index out of bounds!");
    }
    return *(m_DataPtr + idx);
}

void DynamicArray::set(size_t idx, int val) {
    (void)fprintf(stdout, "Trying to set value %d at index %zu\n", val, idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Index %zu out of bounds! Array size is %zu\n", idx, m_Size);
        throw std::out_of_range("Index out of bounds!");
    }
    *(m_DataPtr + idx) = val;
}

size_t DynamicArray::get_size() const {
    (void)fprintf(stdout, "Getting current size: %zu\n", m_Size);
    return m_Size;
}

size_t DynamicArray::get_capacity() const {
    (void)fprintf(stdout, "Getting current capacity: %zu\n", m_Capacity);
    return m_Capacity;
}

void DynamicArray::push_back(int val) {
    (void)fprintf(stdout, "Pushing back value %d\n", val);
    if (m_Size >= m_Capacity) {
        size_t new_capacity = 2 * m_Capacity;
        (void)fprintf(stdout, "Capacity reached, reallocating to new capacity %zu\n", new_capacity);
        int *realloc_ptr = (int *)realloc(m_DataPtr, new_capacity * sizeof(int));
        if (realloc_ptr == nullptr) {
            (void)fprintf(stderr, "Failed to reallocate memory!\n");
            throw std::runtime_error("Failed to reallocate!");
        }
        m_DataPtr = realloc_ptr;
        m_Capacity = new_capacity;
    }
    m_Size += 1;
    set(m_Size - 1, val);
    (void)fprintf(stdout, "New size after push_back: %zu\n", m_Size);
}

int DynamicArray::get_back() const {
    (void)fprintf(stdout, "Getting last element\n");
    if (m_Size == 0) {
        (void)fprintf(stderr, "Attempted to get_back on empty DynamicArray!\n");
        throw std::runtime_error("Invoked get_back on empty DynamicArray!");
    }
    return get(m_Size - 1);
}

int DynamicArray::pop_back() {
    (void)fprintf(stdout, "Popping last element\n");
    if (m_Size == 0) {
        (void)fprintf(stderr, "Attempted to pop_back on empty DynamicArray!\n");
        throw std::runtime_error("Invoked pop_back on empty DynamicArray!");
    }
    int last_element = get(m_Size - 1);
    m_Size -= 1;
    (void)fprintf(stdout, "New size after pop_back: %zu\n", m_Size);
    return last_element;
}

void DynamicArray::insert(size_t idx, int val) {
    (void)fprintf(stdout, "Attempting to insert value %d at index %zu\n", val, idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Attempted to insert at index %zu which is >= size %zu on DynamicArray!\n", idx, m_Size);
        throw std::runtime_error("Attempted to insert at index that is >= size on DynamicArray!");
    }

    (void)fprintf(stdout, "Shifting elements to make room for insertion\n");
    int last_element = get_back();
    for (size_t i = m_Size - 1; i > idx; i--) {
        (void)fprintf(stdout, "Moving element from index %zu to %zu\n", i - 1, i);
        set(i, get(i - 1));
    }

    (void)fprintf(stdout, "Inserting value %d at index %zu\n", val, idx);
    set(idx, val);

    (void)fprintf(stdout, "Pushing back last element %d to accommodate insertion\n", last_element);
    push_back(last_element);

    (void)fprintf(stdout, "Insertion complete. New size: %zu\n", m_Size);
}

void DynamicArray::remove(size_t idx) {
    (void)fprintf(stdout, "Attempting to remove element at index %zu\n", idx);
    if (idx >= m_Size) {
        (void)fprintf(stderr, "Attempted to remove at index %zu which is >= size %zu on DynamicArray!\n", idx, m_Size);
        throw std::runtime_error("Attempted to remove at index that is >= size on DynamicArray!");
    }

    (void)fprintf(stdout, "Shifting elements to fill the gap after removal\n");
    for (size_t i = idx; i < m_Size - 1; i++) {
        (void)fprintf(stdout, "Moving element from index %zu to %zu\n", i + 1, i);
        set(i, get(i + 1));
    }

    m_Size -= 1;
    (void)fprintf(stdout, "Removal complete. New size: %zu\n", m_Size);
}