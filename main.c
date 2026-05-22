#include <stdio.h>
#include "matrix.h"

int main(void) {
    long initial_pos = 0;
    long* inputtxt_offset_ptr = &initial_pos;

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

    Matrix B = load_from_file("input.txt", inputtxt_offset_ptr);
    Matrix C = load_from_file("input.txt", inputtxt_offset_ptr);
    Matrix D = load_from_file("input.txt", inputtxt_offset_ptr);

    print_matrix(A);
    print_matrix(B);
    print_matrix(C);
    print_matrix(D);

    save_to_file(B, "output.txt");
    save_to_file(C, "output.txt");

    return 0;
}