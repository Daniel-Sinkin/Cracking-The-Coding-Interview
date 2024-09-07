#include "Constants.h"
#include <iostream>
#include <utility> // for std::pair

extern void examples_datastructures();
extern void examples_algorithms();

void run_examples() {
    fprintf(stdout, "\n\nDATASTRUCTURE EXAMPLE\n\n");
    examples_datastructures();
    fprintf(stdout, "\n\nALGORITHMS EXAMPLE\n\n");
    examples_algorithms();
}

int main() {
    run_examples();

    return EXIT_SUCCESS;
}