#include <stdio.h>
#include <time.h>
#include <conio.h>
#define COLUMN 15
#define ROWS 25
#define BOX 178
#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

typedef struct
{
    int ponta;
    int laterais;
    int ladoTela;
}car;

void init(char matrix[ROWS][COLUMN]);

void initCar(car *RelampagoMarquinhos);

void putCarOnMatrix(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos);

void printMatrix(char matrix[ROWS][COLUMN], int Animation);

void runtime(char matrix[ROWS][COLUMN]);