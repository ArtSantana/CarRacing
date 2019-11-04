#include <stdio.h>
#include <time.h>
#include <conio.h>
#define COLUMN 15
#define ROWS 25
#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

void init(char matrix[ROWS][COLUMN]);

void printMatrix(char matrix[ROWS][COLUMN]);

void runtime(char matrix[ROWS][COLUMN]);