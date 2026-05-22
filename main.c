#include <stdio.h>
#include "matrix.h"

int main(void) {
    // Test cases
    Matrix A = {
        .data = {
            {0, 9, 8},
            {1, 2, 5},
            {6, 1, -9}
        },
        .rows = 3,
        .cols = 3
    };

    Matrix B = load_from_file("input.txt");

    print_matrix(A);

    save_to_file(B, "output.txt");

    return 0;
}