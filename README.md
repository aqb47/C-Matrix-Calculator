# C-Matrix-Calculator
CLI Matrix Calculator written in C

## How to compile
To compile run - 
```mingw32-make -f MakeFile```

## How to use
You can compile the program as is and run the executable.
 
Currently manual input of a matrix isn't implemented. You have to put the matrix/ matrices you want to work with in an ```input.txt```, and input an operation within the program where you can view the result. You can then choose to save the output to ```output.txt```.

Alternatively with just ```matrix.h, matrix.c, io.c``` you can work with the matrix functions directly as a sort of library. See the prototypes in the header file for more details.

## File IO format
In ```input.txt``` you'll put a matrix in this format -
```
rows cols
(1,1) (1,2) . . . (1, cols)
(2,1) (2,2) . . . (2, cols)
.                    .
.                    .
.                    .
(rows, 1) . . . (rows, cols)
```

e.g.
```
3 3
1 2 3
4 5 6
7 8 9
```
If you save the output in ```output.txt``` you will see a similiar result matrix in this format.