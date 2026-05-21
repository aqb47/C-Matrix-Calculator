#include <stdio.h>
#include <math.h>
#include "matrix.h"

static Matrix negate(Matrix A);
static int count_digits(double value);
static int get_max_width(Matrix A);
static void print_matrix_ends(int width);
static Matrix generate_submatrix(Matrix A, int row, int col);

// Print the matrix A with border
void print_matrix(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    // In case of an empty matrix
    if ((rows == EMPTY_MATRIX.rows) && (cols == EMPTY_MATRIX.cols) && (A.data[0][0] == 0)) {
        printf("ERROR");
        return;
    }

    // How many digits after decimal point to be shown
    int precision = 4;

    int padding = 4;

    // Calculate total width of each element for formatting
    int total_width = get_max_width(A) + precision;

    int ends_width = total_width * cols + padding * cols + 2; 

    // Top border
    print_matrix_ends(ends_width);
    printf("\n");

    // For each row
    for (int i = 0; i < rows; i++) {
        // For each column in row

        // Left border
        printf("| ");

        for (int j = 0; j < cols; j++) {
            // Print the element 
            printf("  %*.*lf  ", total_width, precision, A.data[i][j]);
        }

        // Right border
        printf(" |\n");
    }

    // Bottom border
    print_matrix_ends(ends_width);
    printf("\n");
}

// Print the top and bottom borders of the matrix
void print_matrix_ends(int width) {
    printf("-");
    
    for (int i = 0; i < width; i++) {
        printf(" ");
    }
    
    printf("-");
}

// Get max width of the integer parts of elements in the matrix for formatting
int get_max_width(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    int max_width = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double value = A.data[i][j];
            int width;

            // +1 for decimal point
            width = count_digits(value) + 1; 

            if (width > max_width) {
                max_width = width;
            }
        }
    }

    return max_width;
}

// Get width of integer part of a double
int count_digits(double value) {
    int digits = 0;

    // Specifically for 0.00..
    if (value == 0) {
        digits++;
        return digits;
    }

    // Account for negative sign
    if (value < 0) {
        digits++; 
        value = -value; 
    }

    // Account for leading zero before decimal point
    if (value < 1) {
        digits++; 
    }

    digits += floor(log10(value)) + 1;

    return digits;
}

// Add two matrices A and B with same dimensions
Matrix add(Matrix A, Matrix B) {
    // If dimensions don't match return an empty matrix
    if (A.rows != B.rows || A.cols != B.cols) {
        return EMPTY_MATRIX; 
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

// Negate all elements of A
Matrix negate(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A.data[i][j] = -A.data[i][j];
        }
    }

    return A;
}

// Subtract B from A
Matrix subtract(Matrix A, Matrix B) {
    B = negate(B);

    return add(A, B);
}

// Multiply A and B in order A * B
Matrix multiply(Matrix A, Matrix B) {
    int A_rows = A.rows;
    int A_cols = A.cols;

    int B_rows = B.rows;
    int B_cols = B.cols;

    // Return an empty matrix if dimensions do not match
    if (A_cols != B_rows) {
        return EMPTY_MATRIX;
    }

    // Initialize result matrix C with dimensions A_rows x B_cols
    Matrix C = {.data = {{0}}, .rows = A_rows, .cols = B_cols};

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            for (int k = 0; k < A_cols; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return C;
}

// Swap rows and columns of a matrix
Matrix transpose(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    // Initialize result matrix B with swapped dimensions
    Matrix B = {{{0}}, cols, rows};

    // Go through each row
    for (int i = 0; i < rows; i++) {
        // Go throuch each column
        for (int j = 0; j < cols; j++) {
            // Swap [row][col] and [col][row]
            B.data[j][i] = A.data[i][j];
        }
    }

    return B;
}

// Get determinant from a matrix. n represents rows or cols of square matrix
double determinant(Matrix A) {
    int rows = A.rows;
    int cols = A.cols;

    int n = rows;

    double det_value = 0;

    // Non-square matrices do not have a determinant
    if (rows != cols) {
        return NAN;
    }

    // 1x1 matrices determinant is their first value
    if (n == 1) {
        det_value = A.data[0][0];
    }

    // 2x2 matrices e.g [a b]
    //                  [c d]
    // have a determinant of ad - bc
    else if (n == 2) {
        det_value = A.data[0][0] * A.data[1][1] - A.data[0][1] * A.data[1][0];
    }

    // Recursively generate determinant for n > 2
    else {
        for (int i = 0; i < cols; i++) {
            Matrix submatrix = generate_submatrix(A, 0, i);
            int sign = (i % 2 == 0) ? 1: -1;

            det_value += sign * A.data[0][i] * determinant(submatrix);
        }
    }

    return det_value;
}

// Generate submatrix with respect to row, col position (which is zero-based)
Matrix generate_submatrix(Matrix A, int row, int col) {
    // Initialize submatrix which will have one less row and one less col than initial square matrix
    int A_rows = A.rows;
    int A_cols = A.cols;

    Matrix B = {{{0}}, A_rows - 1, A_cols - 1};

    // For nth entry of submatrix count represents n - 1. This will be used to generate position of each entry of submatrix
    int count = 0;

    // Go throuch each row of initial matrix
    for (int i = 0; i < A_rows; i++) {
        // Go throuch each column of initial matrix
        for (int j = 0; j < A_cols; j++) {
            // Skip rows or columns from position which w.r.t we're finding the submatrix
            if (i == row || j == col) {
                continue;
            }

            // Generate submatrix position
            int submatrix_row = floor(count / (A_rows - 1));
            int submatrix_col = count % (A_rows - 1);

            // Assign values
            B.data[submatrix_row][submatrix_col] = A.data[i][j];
            count++;
        }
    }

    return B;
}