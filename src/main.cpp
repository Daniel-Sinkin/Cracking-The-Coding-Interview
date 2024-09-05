#include "aliases.h"

extern void examples_datastructures();
extern void examples_algorithms();

int main() {
    vector<int> arr1 = {-7, -3, 0, 7};
    vector<int> arr2 = {-17, -8, -6, 1, 4, 5, 12, 13};

    vector<int> arr_merged;

    static const size_t size1 = arr1.size();
    static const size_t size2 = arr2.size();

    size_t left = 0;
    size_t right = 0;

    size_t iteration = 0;
    while ((left < size1) and (right < size2)) {
        (void)fprintf(stdout, "Iteration # %zu.\n", iteration + 1);

        if (arr1[left] < arr2[right]) {
            (void)fprintf(stdout, "\t%d < %d so we push the left value %d.\n", arr1[left], arr2[right], arr1[left]);
            arr_merged.push_back(arr1[left]);
            left += 1;
        } else {
            (void)fprintf(stdout, "\t%d >= %d so we push the right value %d.\n", arr1[left], arr2[right], arr2[right]);
            arr_merged.push_back(arr2[right]);
            right += 1;
        }
    }
    if (left == size1) {
        (void)fprintf(stdout, "\tLeft is done.\n");
        for (size_t i = right + 1; i < size2; i++) {
            arr_merged.push_back(arr2[i]);
        }
    }
    if (right == size2) {
        (void)fprintf(stdout, "\tRight is done.\n");
        for (size_t i = left + 1; i < size1; i++) {
            (void)fprintf(stdout, "Pushing in %d", arr1[i]);
            arr_merged.push_back(arr1[i]);
        }
    }

    for (int v : arr_merged) {
        (void)fprintf(stdout, "%d, ", v);
    }
    (void)fprintf(stdout, "\n");

    // (void)fprintf(stdout, "\n\nDATASTRUCTURE EXAMPLE\n\n");
    // examples_datastructures();
    // (void)fprintf(stdout, "\n\nALGORITHMS EXAMPLE\n\n");
    // examples_algorithms();
    return 0;
}