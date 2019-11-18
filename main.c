#include "lib.h"

int main(void)
{
    char matrix[ROWS][COLUMN];

    if(cursorWindows == 1)
    {
        showConsoleCursor(0);
        CLEAR_SCREEN;
    }

    init(matrix);
    runtime(matrix);

    return 0;
}