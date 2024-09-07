#include "Constants.h"
#include "Datastructures.h"
#include "misc.h"
#include "sorting.h"

#include <chrono>
#include <cstdio>
#include <random>
#include <vector>

void example_linked_list() {
    unique_ptr<LinkedListNode> n3 = make_unique<LinkedListNode>(3);
    unique_ptr<LinkedListNode> n2 = make_unique<LinkedListNode>(2, std::move(n3));
    unique_ptr<LinkedListNode> n1 = make_unique<LinkedListNode>(1, std::move(n2));
    unique_ptr<LinkedListNode> n0 = make_unique<LinkedListNode>(0, std::move(n1));

    LinkedList ll = LinkedList(std::move(n0));

    ll.print_vals();

    fprintf(stdout, "%d\n\n", ll.get_tail().val);

    for (LinkedListNode *x : ll.to_ptr_list()) {
        fprintf(stdout, "%d\n", x->val);
    }
}

void example_tree() {
    unique_ptr<TreeNode> child1 = make_unique<TreeNode>(1);
    unique_ptr<TreeNode> child2 = make_unique<TreeNode>(2);
    unique_ptr<TreeNode> child3 = make_unique<TreeNode>(3);

    vector<unique_ptr<TreeNode>> child1_children;
    child1_children.push_back(make_unique<TreeNode>(4));

    child1->children = std::move(child1_children);

    unique_ptr<TreeNode> root = make_unique<TreeNode>(0);

    root->children.push_back(std::move(child1));
    root->children.push_back(std::move(child2));
    root->children.push_back(std::move(child3));

    for (const unique_ptr<TreeNode> &child : root->children) {
        fprintf(stdout, "Child value: %d\n", child->val);
        if (!child->children.empty()) {
            for (const unique_ptr<TreeNode> &cchild : child->children) {
                fprintf(stdout, "\t%d\n", cchild->val);
            }
        }
    }
}

void example_bst() {
    BST bst(50);
    for (int val : {30, 70, 20, 40, 60, 80, 10, 35, 75, 85}) {
        bst.insert(val);
    }

    fprintf(stdout, "\nBST In-order Traversal:\n");
    bst.get_root()->print_in_order();

    fprintf(stdout, "\n\nBST Pre-order Traversal:\n");
    bst.get_root()->print_pre_order();

    fprintf(stdout, "\n\nBST Post-order Traversal:\n");
    bst.get_root()->print_post_order();
}

void example_trie() {
    Trie trie;

    for (const std::string &word : {"apple", "app", "banana", "bat", "batman"}) {
        trie.insert(word);
        fprintf(stdout, "Inserted '%s' into the trie.\n", word.c_str());
    }

    for (const std::string &word : {"apple", "app", "banana", "bat", "batman", "ban"}) {
        fprintf(stdout, "Contains '%s': %s\n", word.c_str(), trie.contains_word(word) ? "true" : "false");
    }

    for (const std::string &prefix : {"app", "ban", "bat", "car"}) {
        fprintf(stdout, "Prefix '%s': %s\n", prefix.c_str(), trie.contains_prefix(prefix) ? "true" : "false");
    }
}

void example_min_heap() {
    MinHeap heap;

    for (int value : {20, 5, 15, 10, 2, 25, 30}) {
        heap.insert(value);
        fprintf(stdout, "Inserted %d into the MinHeap.\n", value);
    }

    fprintf(stdout, "\nHeap structure:\n");
    heap.print();

    fprintf(stdout, "\nPopping values from the MinHeap:\n");
    while (true) {
        try {
            int min_value = heap.pop_min();
            fprintf(stdout, "Popped min value: %d\n", min_value);
        } catch (const std::runtime_error &e) {
            fprintf(stdout, "(Correctly Predicted) Error: %s\n", e.what());
            break;
        }
    }
}

void example_graph() {
    Graph graph;
    // Create 12 nodes
    for (int i = 0; i < 12; i++) {
        (void)graph.createNewNode(i);
    }

    // clang-format off
    constexpr array<std::pair<size_t, size_t>, 26> edges = {{
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9},
        {4, 10}, {5, 11}, {6, 0}, {7, 1}, {8, 2}, {9, 3}, {10, 4}, {11, 5},
        {6, 8}, {7, 9}, {10, 11}, {0, 10}, {1, 11}, {2, 9}, {3, 8}, {4, 7}, {5, 6}
    }};
    // clang-format on

    for (const auto &edge : edges) {
        size_t idx1 = edge.first;
        size_t idx2 = edge.second;
        fprintf(stdout, "Trying to add %zu -> %zu\n", idx1, idx2);

        if (!graph.addEdge(idx1, idx2)) {
            fprintf(stdout, "Failed to create edge: %zu -> %zu\n", idx1, idx2);
        }
    }

    bool found = false;
    int value_to_find;

    value_to_find = 11;
    found = graph.findBFS(0, value_to_find);
    fprintf(stdout, "\nBFS: Looking for %d: %s", value_to_find, found ? "Found" : "Not Found");

    value_to_find = 23;
    found = graph.findBFS(0, value_to_find);
    fprintf(stdout, "\nBFS: Looking for %d: %s", value_to_find, found ? "Found" : "Not Found");

    value_to_find = 11;
    found = graph.findDFS(0, value_to_find);
    fprintf(stdout, "\nDFS: Looking for %d: %s", value_to_find, found ? "Found" : "Not Found");

    value_to_find = 23;
    found = graph.findDFS(0, value_to_find);
    fprintf(stdout, "\nDFS: Looking for %d: %s", value_to_find, found ? "Found" : "Not Found");
}

void example_dynamic_array() {
    fprintf(stdout, "Creating DynamicArray\n");
    DynamicArray arr;

    // Filling array with initial values
    fprintf(stdout, "\nFilling array with initial values\n");
    for (int i = 0; i < 8; i++) {
        arr.push_back(10 * (i + 1));
    }

    fprintf(stdout, "\nPrinting initial values\n");
    for (size_t i = 0; i < arr.get_size(); i++) {
        fprintf(stdout, "%d\n", arr.get(i));
    }

    // Test inserting at a valid index
    fprintf(stdout, "\nInserting element at index 4\n");
    arr.insert(4, 99);

    // Test invalid insert index
    try {
        fprintf(stdout, "\nInserting element at invalid index\n");
        arr.insert(20, 100); // Out of bounds
    } catch (const std::runtime_error &e) {
        fprintf(stdout, "Caught expected error: %s\n", e.what());
    }

    // Trigger capacity expansion
    fprintf(stdout, "\nAdding more elements to trigger capacity increase\n");
    for (int i = 8; i < 16; i++) {
        arr.push_back(-10 * (i + 1));
    }

    // Print all values after expansion
    fprintf(stdout, "\nPrinting all values after expansion\n");
    for (size_t i = 0; i < arr.get_size(); i++) {
        fprintf(stdout, "%d\n", arr.get(i));
    }

    // Getting final capacity and size
    fprintf(stdout, "\nGetting final capacity and size\n");
    fprintf(stdout, "Final capacity = %zu, final size = %zu\n", arr.get_capacity(), arr.get_size());

    // Test pop_back
    fprintf(stdout, "\nTesting pop_back\n");
    int popped_value = arr.pop_back();
    fprintf(stdout, "Popped value: %d\n", popped_value);

    // Test invalid pop on an empty array
    fprintf(stdout, "\nTesting pop_back on empty array\n");
    try {
        for (size_t i = 0; i < arr.get_size(); i++) {
            arr.pop_back();
        }
        arr.pop_back(); // This should throw an error
    } catch (const std::runtime_error &e) {
        fprintf(stdout, "Caught expected error: %s\n", e.what());
    }

    // Test get_back on non-empty array
    fprintf(stdout, "\nTesting get_back\n");
    int back_value = arr.get_back();
    fprintf(stdout, "Back value: %d\n", back_value);

    // Test invalid get_back on empty array
    fprintf(stdout, "\nTesting get_back on empty array\n");
    try {
        for (size_t i = 0; i < arr.get_size(); i++) {
            arr.pop_back();
        }
        arr.get_back(); // This should throw an error
    } catch (const std::runtime_error &e) {
        fprintf(stdout, "Caught expected error: %s\n", e.what());
    }

    // Test remove
    fprintf(stdout, "\nTesting remove at index 2\n");
    arr.remove(2);

    // Test invalid remove
    fprintf(stdout, "\nTesting remove at invalid index\n");
    try {
        arr.remove(20); // Out of bounds
    } catch (const std::runtime_error &e) {
        fprintf(stdout, "Caught expected error: %s\n", e.what());
    }

    fprintf(stdout, "\nEnd of main function, DynamicArray will be destroyed\n");
}

void examples_datastructures() {
    fprintf(stdout, "\n\nEXAMPLE: Linked Lists.\n\n");
    example_linked_list();

    fprintf(stdout, "\n\nEXAMPLE: Tree.\n\n");
    example_tree();

    fprintf(stdout, "\n\nEXAMPLE: Binary Search Tree (BST).\n\n");
    example_bst();

    fprintf(stdout, "\n\nEXAMPLE: Trie.\n\n");
    example_trie();

    fprintf(stdout, "\n\nEXAMPLE: MinHeap.\n\n");
    example_min_heap();

    fprintf(stdout, "\n\nEXAMPLE: Graph.\n\n");
    example_graph();

    fprintf(stdout, "\n\nEXAMPLE: DynamicArray.\n\n");
    example_dynamic_array();
}

void example_sort_heap() {
    const static int HUNDRED_MILLION = 100 * 1000 * 1000;
    const int ARRAY_SIZE = 1000 * 1000;
    vector<int> arr(ARRAY_SIZE);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-HUNDRED_MILLION, HUNDRED_MILLION);
    for (int &num : arr) {
        num = dis(gen);
    }
    fprintf(stdout, "Original array (first 20 elements): ");
    for (size_t i = 0; i < 20; ++i) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "...\n");

    auto start = std::chrono::high_resolution_clock::now();
    heapsort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    double elapsed_seconds = elapsed.count() / 1000.0;

    fprintf(stdout, "Sorted array (first 20 elements): ");
    for (size_t i = 0; i < 20; ++i) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "...\n");

    double n_log_n = ARRAY_SIZE * std::log2(ARRAY_SIZE);
    double time_per_operation = elapsed_seconds / n_log_n;

    fprintf(stdout, "Array size: %d\n", ARRAY_SIZE);
    fprintf(stdout, "Actual time taken: %.6f seconds\n", elapsed_seconds);
    fprintf(stdout, "O(n log n) operations: %.2f\n", n_log_n);
    fprintf(stdout, "Time per O(n log n) operation: %.9f seconds\n", time_per_operation);

    // Verify if the array is sorted
    bool is_sorted = std::is_sorted(arr.begin(), arr.end());
    fprintf(stdout, "Is the array sorted? %s\n", is_sorted ? "Yes" : "No");

    // Predict time for different array sizes
    for (int size : {10000, 100000, 1000000, 10000000}) {
        double predicted_time = (size * std::log2(size)) * time_per_operation;
        fprintf(stdout, "Predicted time for %d elements: %.6f seconds\n", size, predicted_time);
    }
}

void example_sort_merge_not_inplace() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    fprintf(stdout, "Original array: ");
    for (int num : arr) {
        fprintf(stdout, "%d ", num);
    }
    fprintf(stdout, "\n");

    vector<int> sorted_arr = sort_merge_not_inplace(arr);

    fprintf(stdout, "Sorted array: ");
    for (int num : sorted_arr) {
        fprintf(stdout, "%d ", num);
    }
    fprintf(stdout, "\n");
}

void example_binary_search() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int val_to_find;
    size_t found_at;

    val_to_find = 10;
    found_at = binary_search(arr, val_to_find);
    if (found_at == arr.size()) {
        fprintf(stdout, "Couldn't find the value %d.\n", val_to_find);
    } else {
        fprintf(stdout, "Found the value at index %zu.\n", found_at);
    }

    val_to_find = -1;
    found_at = binary_search(arr, val_to_find);
    if (found_at == arr.size()) {
        fprintf(stdout, "Couldn't find the value %d.\n", val_to_find);
    } else {
        fprintf(stdout, "Found the value at index %zu.\n", found_at);
    }
}
void example_quick_sort() {
    const static int HUNDRED_MILLION = 100 * 1000 * 1000;
    const int ARRAY_SIZE = 1000 * 1000;
    vector<int> arr(ARRAY_SIZE);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-HUNDRED_MILLION, HUNDRED_MILLION);

    for (int &num : arr) {
        num = dis(gen);
    }

    fprintf(stdout, "Original array (first 20 elements): ");
    for (size_t i = 0; i < 20; ++i) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "...\n");

    // Timing the quicksort algorithm
    auto start = std::chrono::high_resolution_clock::now();
    quicksort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    double elapsed_seconds = elapsed.count() / 1000.0;

    fprintf(stdout, "Sorted array (first 20 elements): ");
    for (size_t i = 0; i < 20; ++i) {
        fprintf(stdout, "%d ", arr[i]);
    }
    fprintf(stdout, "...\n");

    double n_log_n = ARRAY_SIZE * std::log2(ARRAY_SIZE);
    double time_per_operation = elapsed_seconds / n_log_n;

    fprintf(stdout, "Array size: %d\n", ARRAY_SIZE);
    fprintf(stdout, "Actual time taken: %.6f seconds\n", elapsed_seconds);
    fprintf(stdout, "O(n log n) operations: %.2f\n", n_log_n);
    fprintf(stdout, "Time per O(n log n) operation: %.9f seconds\n", time_per_operation);

    // Verify if the array is sorted
    bool is_sorted = std::is_sorted(arr.begin(), arr.end());
    fprintf(stdout, "Is the array sorted? %s\n", is_sorted ? "Yes" : "No");

    // Predict time for different array sizes
    for (int size : {10000, 100000, 1000000, 10000000}) {
        double predicted_time = (size * std::log2(size)) * time_per_operation;
        fprintf(stdout, "Predicted time for %d elements: %.6f seconds\n", size, predicted_time);
    }
}

void examples_algorithms() {
    fprintf(stdout, "\n\nEXAMPLE: Heap Sort.\n\n");
    example_sort_heap();

    fprintf(stdout, "\n\nEXAMPLE: Merge Sort (Not Inplace).\n\n");
    example_sort_merge_not_inplace();

    fprintf(stdout, "\n\nEXAMPLE: Quicksort.\n\n"); // Add quicksort example
    example_quick_sort();

    fprintf(stdout, "\n\nEXAMPLE: Binary Search.\n\n");
    example_binary_search();
}