#ifndef MATRIX_h
#define MATRIX_h

#define MAX_SIZE 5 // 5x5 matrix as max size

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