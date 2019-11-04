#include "lib.h"

void init(char matrix[ROWS][COLUMN])
{
    int i,j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMN; j++)
        {
            matrix[i][j] = 32; // 32 is equal to space
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMN])
{
    int i,j;
    for(i=0; i<ROWS; i++)
        {
            for(j=0; j<COLUMN; j++)
            {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}