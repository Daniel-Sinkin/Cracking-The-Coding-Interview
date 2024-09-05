#include "aliases.h"
#include "datastructures.h"
#include <iostream>

extern void examples_datastructures();
extern void examples_algorithms();

int main() {
    // Create 12 graph nodes
    GraphNode *A = new GraphNode(1);
    GraphNode *B = new GraphNode(2);
    GraphNode *C = new GraphNode(3);
    GraphNode *D = new GraphNode(4);
    GraphNode *E = new GraphNode(5);
    GraphNode *F = new GraphNode(6);
    GraphNode *G = new GraphNode(7);
    GraphNode *H = new GraphNode(8);
    GraphNode *I = new GraphNode(9);
    GraphNode *J = new GraphNode(10);
    GraphNode *K = new GraphNode(11);
    GraphNode *L = new GraphNode(12);

    // Adding 20 directed edges between the nodes
    A->appendChild(B);
    A->appendChild(C);
    A->appendChild(D);

    B->appendChild(E);
    B->appendChild(F);

    C->appendChild(G);

    D->appendChild(H);
    D->appendChild(I);

    E->appendChild(J);

    F->appendChild(K);

    G->appendChild(L);

    H->appendChild(B); // Example of a cycle: H -> B

    I->appendChild(C); // Example of another cycle: I -> C
    I->appendChild(F);

    J->appendChild(G);

    K->appendChild(A); // Another cycle: K -> A
    K->appendChild(D);

    L->appendChild(H);

    (void)fprintf(stdout, "\n\n");

    (void)fprintf(stdout, "\n\n");

    // Print the graph structure
    std::cout << "Graph structure:" << std::endl;
    std::vector<GraphNode *> allNodes = {A, B, C, D, E, F, G, H, I, J, K, L};
    for (GraphNode *node : allNodes) {
        std::cout << "Node " << node->getValue() << " children: ";
        for (GraphNode *child : node->getChildren()) {
            std::cout << child->getValue() << " ";
        }
        std::cout << std::endl;
    }

    // Clean up dynamic memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;
    delete H;
    delete I;
    delete J;
    delete K;
    delete L;

    // (void)fprintf(stdout, "\n\nDATASTRUCTURE EXAMPLE\n\n");
    // examples_datastructures();
    // (void)fprintf(stdout, "\n\nALGORITHMS EXAMPLE\n\n");
    // examples_algorithms();

    return 0;
}