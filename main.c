#include "lib.h"

int main(void)
{
    char matrix[ROWS][COLUMN];    
    car RelampagoMarquinhos;
   
    showConsoleCursor(0);
    CLEAR_SCREEN;

    initCar(&RelampagoMarquinhos);
    init(matrix);    
    runtime(matrix, &RelampagoMarquinhos);

    return 0;
}