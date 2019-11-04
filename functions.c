#include "lib.h"

void init(char matrix[ROWS][COLUMN])
{
    int i,j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMN; j++)
        {
            matrix[i][j] = 32; // 32 is equal to space
            if(i == 0 || i == COLUMN - 1) matrix[i][j] == 42; // equal to *
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMN])
{
    int i, j;    
    for(i=0; i<ROWS; i++)
        {
            if(i % 2 == 0)
            {
                matrix[i][1] == 178; // BARRAS
                matrix[i][COLUMN-2] == 178; // BARRAS                                    
            }
            else
            {
                matrix[i][1] == 178; // BARRAS
                matrix[i][COLUMN-2] == 178; // BARRAS                    
            }                
            for(j=0; j<COLUMN; j++)
            {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}

void runtime(char matrix[ROWS][COLUMN])
{
    while(1==1)
    {
        printMatrix(matrix);
        CLEAR_SCREEN;
    }
}