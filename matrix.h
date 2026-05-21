#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <math.h>

// 5x5 matrix as max size
#define MAX_SIZE 5 
// Empty matrix to return when an operation fails
#define EMPTY_MATRIX (Matrix) {{{0}}, 0, 0} 

typedef struct {
    float data[MAX_SIZE][MAX_SIZE];
    int rows;
    int cols;
} Matrix;

Matrix add(Matrix A, Matrix B);
Matrix subtract(Matrix A, Matrix B);

Matrix multiply(Matrix A, Matrix B);

Matrix transpose(Matrix A);

float determinant(Matrix A);

Matrix inverse(Matrix A);

void print_matrix(Matrix A);

void save_to_file(Matrix A, const char* filename);
Matrix load_from_file(const char* filename);

#endif 