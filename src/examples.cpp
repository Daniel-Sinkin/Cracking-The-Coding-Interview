#include "aliases.h"
#include "datastructures.h"
#include <cstdio>
#include <vector>

void example_linked_list() {
    auto n3 = make_unique<Node>(3);
    auto n2 = make_unique<Node>(2, std::move(n3));
    auto n1 = make_unique<Node>(1, std::move(n2));
    auto n0 = make_unique<Node>(0, std::move(n1));

    LinkedList ll = LinkedList(std::move(n0));

    ll.print_vals();

    (void)printf("%d\n\n", ll.get_tail().val);

    for (Node *x : ll.to_ptr_list()) {
        (void)printf("%d\n", x->val);
    }
}
void example_tree() {
    UP_TreeNode child1 = make_unique<TreeNode>(1);
    UP_TreeNode child2 = make_unique<TreeNode>(2);
    UP_TreeNode child3 = make_unique<TreeNode>(3);

    vector<UP_TreeNode> child1_children;
    child1_children.push_back(make_unique<TreeNode>(4));

    child1->children = std::move(child1_children);

    UP_TreeNode root = make_unique<TreeNode>(0);

    root->children.push_back(std::move(child1));
    root->children.push_back(std::move(child2));
    root->children.push_back(std::move(child3));

    for (const UP_TreeNode &child : root->children) {
        printf("Child value: %d\n", child->val);
        if (!child->children.empty()) {
            for (const UP_TreeNode &cchild : child->children) {
                printf("\t%d\n", cchild->val);
            }
        }
    }
}

void run_all_examples() {
    (void)fprintf(stdout, "\n\n EXAMPLE: Linked Lists.\n\n");
    example_linked_list();
    (void)fprintf(stdout, "\n\n EXAMPLE: Tree\n\n");
    example_tree();
}