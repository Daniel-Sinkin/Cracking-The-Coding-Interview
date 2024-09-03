#include "datastructures.h"
#include <cstdio>
#include <vector>

void example_linked_list() {
    Node n3 = Node(3);
    Node n2 = Node(2, &n3);
    Node n1 = Node(1, &n2);
    Node n0 = Node(0, &n1);
    LinkedList ll = LinkedList(&n0);

    ll.print_vals();

    (void)printf("%d\n\n", ll.get_tail()->val);

    for (Node *x : ll.to_ptr_list()) {
        (void)printf("%d\n", x->val);
    }
}

void run_all_examples() {
    example_linked_list();
}