#include "Constants.h"
#include "datastructures.h"
#include <iostream>
#include <utility> // for std::pair

extern void examples_datastructures();
extern void examples_algorithms();

void run_examples() {
    (void)fprintf(stdout, "\n\nDATASTRUCTURE EXAMPLE\n\n");
    examples_datastructures();
    (void)fprintf(stdout, "\n\nALGORITHMS EXAMPLE\n\n");
    examples_algorithms();
}

int main() {
    run_examples();
    return 0;
}