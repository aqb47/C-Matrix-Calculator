#include <stdio.h>
#include "matrix.h"

void print_matrix(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", A.data[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}