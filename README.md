# C-Matrix-Calculator
CLI Matrix Calculator written in C

## How to compile
To compile run - 
```
mingw32-make -f MakeFile
```

## File IO format
In input.txt you'll put a matrix in this format -
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