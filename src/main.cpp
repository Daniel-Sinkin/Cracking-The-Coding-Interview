#include "datastructures.h"
#include <iostream>
#include <vector>

int main() {
    Node n3 = Node(3);
    Node n2 = Node(2, &n3);
    Node n1 = Node(1, &n2);
    Node n0 = Node(0, &n1);
    LinkedList ll = LinkedList(&n0);

    ll.print_vals();

    std::cout << ll.get_head()->val << std::endl;

    std::cout << std::endl;

    for (Node *x : ll.to_ptr_list()) {
        std::cout << x->val << std::endl;
    }

    return 0;
}