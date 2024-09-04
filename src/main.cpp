#include "aliases.h"
#include "datastructures.h"

extern void run_all_examples();

void minheap_print(const vector<int> &minheap) {
    int layer = 0;
    int exponented = 1;

    fprintf(stdout, "Root: %d\n", minheap[0]);
    bool is_running = true;
    while (is_running) {
        for (int i = 0; i < exponented; i++) {
            if (exponented + i == minheap.size()) {
                is_running = false;
                break;
            }
            (void)fprintf(stdout, "%d. Layer: 2^%d + %d = %d\n", layer + 1, layer, i, minheap[exponented + i]);
        }
        exponented *= 2;
        layer += 1;
    }
}

void minheap_insert(vector<int> &minheap, int value) {
    (void)fprintf(stdout, "\nInserting %d into the minheap.\n", value);
    minheap.push_back(value);
    int last_element_idx = minheap.size() - 1;
    if (last_element_idx < 3) {
        if (minheap[last_element_idx] < minheap[0]) {
            std::swap(minheap[0], minheap[last_element_idx]);
        }
        return;
    }

    int idx = minheap.size() - 1;
    int idx_tmp = idx;
    int layer = -1;
    int layer_idx_start = 1;
    while (idx_tmp > 1) {
        idx_tmp >>= 1;
        layer += 1;
        layer_idx_start <<= 1;
    }
    layer_idx_start >>= 1;
    int parent_layer_idx_start = layer_idx_start >> 1;
    int parent_layer_idx_end = layer_idx_start << 1;
    /*
    To determine which is is parent node we do the following:
    suppose we have idx=14 then we can determine that the current layer is
        8..15
    and therefore the parent layer is
        4..7
    We can split 8..15 into blocks of size 2 to get
        [8, 9], [10, 11], [12, 13], [14, 15]
    which correspond to
        4, 5, 6, 7
    respectively, the pattern is a floored division by 2:
        9 = 8 + 0 * 2 + 1 -> 9 // 2 = 4
        13 = 8 + 2 * 2 + 1 -> 13 // 2 = 4 + 1 * 2 = 6
    */

    (void)fprintf(stdout, "The inserted value is at the %d. layer\n", layer + 1);
    (void)fprintf(stdout, "The values that correspond to this are:");
    for (size_t i = parent_layer_idx_start; i < 2 * parent_layer_idx_start; i++) {
        (void)fprintf(stdout, "%d <%zu>, ", minheap[i], i);
    }
    (void)fprintf(stdout, "\n");

    /*
    TODO: Add the bubbling up of the value.
    */
}

int main() {
    // run_all_examples();

    vector<int> minheap = {4, 50, 7, 55, 90, 87};
    minheap_print(minheap);

    int y = 2;
    minheap_insert(minheap, y);

    minheap_print(minheap);

    return 0;
}