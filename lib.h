#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define COLUMN 15
#define ROWS 25
#define BOX 178
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define SPACE 32
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

    int trackingColuna; // PARA OS INIMIGOS
    int trackingLinha; // PARA OS INIMIGOS
}car;

void init(char matrix[ROWS][COLUMN]);

void initCar(car *RelampagoMarquinhos);

void initEnemy(car *Enemy);

void putCarOnMatrix(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos);

void putEnemyOnMatrix(char matrix[ROWS][COLUMN], car *Enemy);

void eraseEnemy(char matrix[ROWS][COLUMN], car *Enemy);

void movimentMarquinhos(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos, int key);

void printMatrix(char matrix[ROWS][COLUMN], int Animation);

void runtime(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos, car *Enemy);