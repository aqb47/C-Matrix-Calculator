#include <stdio.h>
#include "matrix.h"

int main(void) {
    Matrix A = {.data = {{2, 3}, {4, 5}}, .rows = 2, .cols = 2};
    Matrix B = {.data = {{-1, 0}, {0, 1}}, .rows = 2, .cols = 2};

    Matrix C = add(A, B);
    Matrix D = subtract(A, B);

    print_matrix(A);
    print_matrix(B);

    print_matrix(C);
    print_matrix(D);

    scanf("%*c"); 

    return 0;
}