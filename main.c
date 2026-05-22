// TEMPORARY MAIN FILE - I'LL MAKE IT BETTER LATER 

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define INPUT_SCREEN 0
#define SINGLE_OPERATION_SCREEN 2
#define MULTI_OPERATION_SCREEN 3
#define MATRIX_NUMBER_SCREEN 4

int show_menu(int argument);
void clear_terminal(void);

int main(void) {
    long initial_pos = 0;
    long* inputtxt_offset_ptr = &initial_pos;

    Matrix result_matrix, A, B;

    int input_choice, number_choice, operation_choice;

    // Show input screen and matrix number screen
    input_choice = show_menu(INPUT_SCREEN);

    number_choice = show_menu(MATRIX_NUMBER_SCREEN);

    // Show matrix number screen and get matrices from input.txt
    if (input_choice == 1) {
        A = load_from_file("input.txt", inputtxt_offset_ptr);

        printf("A: \n");
        print_matrix(A);
        printf("\n");

        // In case of second matrix
        if (number_choice == 2) {
            B = load_from_file("input.txt", inputtxt_offset_ptr);

            printf("B: \n");
            print_matrix(B);
            printf("\n");
        }
    }

    // Show matrix number screen and get matrices from user
    else if (input_choice == 2) {
        // CHANGE LATER
        A = load_from_file("input.txt", inputtxt_offset_ptr);

        // In case of second matrix
        if (number_choice == 2) {
            B = load_from_file("input.txt", inputtxt_offset_ptr);
        }
    }

    // Perform single matrix operation
    if (number_choice == 1) {
        operation_choice = show_menu(SINGLE_OPERATION_SCREEN);

        // Transposition
        if (operation_choice == 1) {
            result_matrix = transpose(A);
            print_matrix(result_matrix);
        }

        // Determinant
        else if (operation_choice == 2) {
            printf("Determinant: %lf\n", determinant(A));
        }

        // Inversion
        else if (operation_choice == 3) {
            result_matrix = inverse(A);
            print_matrix(result_matrix);
        }
    }

    // Perform multi matrix operation
    else if (number_choice == 2) {
        operation_choice = show_menu(MULTI_OPERATION_SCREEN);

        // Addition
        if (operation_choice == 1) {
            result_matrix = add(A, B);
        }

        // Subtraction
        else if (operation_choice == 2) {
            result_matrix = subtract(A, B);
        }

        // Multiplication
        else if (operation_choice == 3) {
            result_matrix = multiply(A, B);
        }

        print_matrix(result_matrix);
    }


    scanf("%d", &number_choice);

    return 0;
}

int show_menu(int argument) {
    int choice;

    printf("MATRIX CALCULATOR\n\n");
    printf("(Use the readme.md for help!)\n\n");

    if (argument == INPUT_SCREEN) {
        printf("INPUT TYPE:\n\n");
        
        printf("1. Import matrices from 'input.txt'.\n");
        printf("2. Import matrices directly.\n\n");
    }

    else if (argument == SINGLE_OPERATION_SCREEN) {
        printf("SINGLE OPERATION TYPE:\n\n");
        
        printf("1. Transpose (At)\n");
        printf("2. Determinant (|A|)\n");
        printf("3. Inverse (A^-1)\n\n");
    }

    else if (argument == MULTI_OPERATION_SCREEN) {
        printf("MULTI OPERATION TYPE:\n\n");

        printf("1. Add (A+B)\n");
        printf("2. Subtract (A-B)\n");
        printf("3. Multiply (A*B)\n\n");
    }

    else if (argument == MATRIX_NUMBER_SCREEN) {
        printf("MATRIX NUMBER:\n\n");

        printf("1. 1 matrix. (Inversion, Transposition, Determinant operations)\n");
        printf("2. 2 matrices. (Addition, Subtraction, Multiplication operations)\n\n");
    }

    scanf("%i", &choice);

    clear_terminal();

    return choice;
}

void clear_terminal(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}