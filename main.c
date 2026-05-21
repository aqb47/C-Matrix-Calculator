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

    print_matrix(inverse(A));

    // This should be an identity matrix
    print_matrix(multiply(A, inverse(A)));

    return 0;
}