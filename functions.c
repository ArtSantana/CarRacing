#include "lib.h"

void init(char matrix[ROWS][COLUMN])
{
    int i,j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMN; j++)
        {
            matrix[i][j] = 32; // 32 is equal to space            
            matrix[i][0] = '*';
            matrix[i][COLUMN - 1] = '*';
        }
    }    

}

void printMatrix(char matrix[ROWS][COLUMN])
{
    int i, j, k, switcher = 0;
    switcher = switcher == 0 ? 1 : 0;
    for(i=0; i<ROWS; i++)
        {            
            for(j=0; j<COLUMN; j++)
            {
                if(switcher == 0)
                {
                    if(i % 2 == 0)
                    {
                        for(k=0; k<ROWS; k++)
                        {
                            matrix[k][1] = 32;
                        }
                        matrix[i][1] = 178;
                        matrix[i][COLUMN -2] = 178;
                    }
                }
                else if(switcher == 1)
                {
                    if(i % 2 != 0)
                    {
                        for(k=0; k<ROWS; k++)
                        {
                            matrix[k][1] = 32;
                        }
                        matrix[i][1] = 178;
                        matrix[i][COLUMN -2] = 178;
                    }
                }
                
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