#include <stdio.h>
#include "matrix.h"

void print_matrix(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    // For each row
    for (int i = 0; i < rows; i++) {
        // For each column in row
        for (int j = 0; j < cols; j++) {
            // Print the element with 2 decimal places
            printf("%.2f ", A.data[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

Matrix add(Matrix A, Matrix B) {
    // If dimensions don't match return an empty matrix
    if (A.rows != B.rows || A.cols != B.cols) {
        return (Matrix){{{0}}, 0, 0}; 
    }

    // Initialize result matrix C
    int rows = A.rows;
    int cols = A.cols;

    Matrix C = {.data = {{0}}, .rows = rows, .cols = cols};

    // For each row
    for (int i = 0; i < rows; i++) {
        // For each column in row
        for (int j = 0; j < cols; j++) {
            // Add entries from A and B into C
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }

    return C;
}