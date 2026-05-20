#include <stdio.h>
#include "matrix.h"

int main(void) {
    Matrix A = {.data = {{2, 3}, {4, 5}}, .rows = 2, .cols = 2};

    print_matrix(A);

    printf("Matrix A has %d rows and %d columns.\n", A.rows, A.cols);

    return 0;
}