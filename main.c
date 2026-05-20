#include <stdio.h>
#include "matrix.h"

int main(void) {
    // Test cases
    Matrix A = {
        .data = {
            {2, 3},
            {4, 5}
        }, 
        .rows = 2, 
        .cols = 2};
    
    Matrix B = {
        .data = {
            {-1, 0},
            {0, 1}
        },
        .rows = 2,
        .cols = 2
    };

    Matrix C = add(A, B);
    Matrix D = subtract(A, B);

    Matrix E = {
        .data = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        .rows = 3,
        .cols = 3
    };
    
    Matrix F = {
        .data = {
            {1, 2}, 
            {3, 4}, 
            {5, 6}, 
            {7, 8}
        }, 
        .rows = 4, 
        .cols = 2
    };

    Matrix G = {
        .data = {
            {111111, 121212, 32323, 3231},
            {121, 333331212121332111, 233, 2},
            {121, 129949, 1, 112},
            {0.0001, 121218, 12, 1222}
        },
        .rows = 4,
        .cols = 4
    };

    print_matrix(A);
    printf("+\n");
    
    print_matrix(B);
    printf("=\n");
    
    print_matrix(C);
    printf("\n");

    print_matrix(D);
    printf("\n");
    
    print_matrix(E);
    printf("\n");

    print_matrix(F);
    printf("\n");

    print_matrix(G);
    printf("\n");

    scanf("%*c"); 

    return 0;
}