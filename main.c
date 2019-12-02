#include "lib.h"

int main(void)
{
    char matrix[ROWS][COLUMN];    
    car RelampagoMarquinhos;
    car ChickHicks;
    car StripWeathers;
   
    showConsoleCursor(0);
    CLEAR_SCREEN;

    initCar(&RelampagoMarquinhos);
    init(matrix);
    initEnemy(&ChickHicks);
    runtime(matrix, &RelampagoMarquinhos, &ChickHicks);

    return 0;
}