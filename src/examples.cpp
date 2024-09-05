#include "aliases.h"
#include "datastructures.h"
#include <cstdio>
#include <vector>

void example_linked_list() {
    unique_ptr<LinkedListNode> n3 = make_unique<LinkedListNode>(3);
    unique_ptr<LinkedListNode> n2 = make_unique<LinkedListNode>(2, std::move(n3));
    unique_ptr<LinkedListNode> n1 = make_unique<LinkedListNode>(1, std::move(n2));
    unique_ptr<LinkedListNode> n0 = make_unique<LinkedListNode>(0, std::move(n1));

    LinkedList ll = LinkedList(std::move(n0));

    ll.print_vals();

    (void)printf("%d\n\n", ll.get_tail().val);

    for (LinkedListNode *x : ll.to_ptr_list()) {
        (void)printf("%d\n", x->val);
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
        printf("Child value: %d\n", child->val);
        if (!child->children.empty()) {
            for (const unique_ptr<TreeNode> &cchild : child->children) {
                printf("\t%d\n", cchild->val);
            }
        }
    }
}

void example_bst() {
    BST bst(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(35);
    bst.insert(75);
    bst.insert(85);

    printf("\nBST In-order Traversal:\n");
    bst.get_root()->print_in_order();

    printf("\n\nBST Pre-order Traversal:\n");
    bst.get_root()->print_pre_order();

    printf("\n\nBST Post-order Traversal:\n");
    bst.get_root()->print_post_order();
}

void example_trie() {
    Trie trie;

    for (const std::string &word : {"apple", "app", "banana", "bat", "batman"}) {
        trie.insert(word);
        (void)fprintf(stdout, "Inserted '%s' into the trie.\n", word.c_str());
    }

    for (const std::string &word : {"apple", "app", "banana", "bat", "batman", "ban"}) {
        (void)fprintf(stdout, "Contains '%s': %s\n", word.c_str(), trie.contains_word(word) ? "true" : "false");
    }

    for (const std::string &prefix : {"app", "ban", "bat", "car"}) {
        (void)fprintf(stdout, "Prefix '%s': %s\n", prefix.c_str(), trie.contains_prefix(prefix) ? "true" : "false");
    }
}

void example_min_heap() {
    MinHeap heap;

    vector<int> values_to_insert = {20, 5, 15, 10, 2, 25, 30};

    // Insert values into the heap
    for (int value : values_to_insert) {
        heap.insert(value);
        printf("Inserted %d into the MinHeap.\n", value);
    }

    // Print heap structure
    printf("\nHeap structure:\n");
    heap.print();

    // Pop the minimum value multiple times
    printf("\nPopping values from the MinHeap:\n");
    while (true) {
        try {
            int min_value = heap.pop_min();
            printf("Popped min value: %d\n", min_value);
        } catch (const std::runtime_error &e) {
            printf("(Correctly Predicted) Error: %s\n", e.what());
            break;
        }
    }
}

void run_all_examples() {
    (void)fprintf(stdout, "\n\nEXAMPLE: Linked Lists.\n\n");
    example_linked_list();

    (void)fprintf(stdout, "\n\nEXAMPLE: Tree.\n\n");
    example_tree();

    (void)fprintf(stdout, "\n\nEXAMPLE: Binary Search Tree (BST).\n\n");
    example_bst();

    (void)fprintf(stdout, "\n\nEXAMPLE: Trie.\n\n");
    example_trie();

    (void)fprintf(stdout, "\n\nEXAMPLE: MinHeap.\n\n");
    example_min_heap();
}