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

void printMatrix(char matrix[ROWS][COLUMN], int sideAnimation)
{
    int i, j, k;
    for(i=0; i<ROWS; i++)
        {            
            for(j=0; j<COLUMN; j++)
            {                  
                if(sideAnimation == 0)
                {
                    if(i % 2 == 0)
                    {
                        for(k=0; k<ROWS; k++)
                        {
                            matrix[k][1] = 32;
                            matrix[k][COLUMN - 2] = 32;
                        }
                        matrix[i][1] = 178;
                        matrix[i][COLUMN -2] = 178;
                    }
                }
                else
                {
                    if(i % 2 != 0)
                    {
                        for(k=0; k<ROWS; k++)
                        {
                            matrix[k][1] = 32;
                            matrix[k][COLUMN - 2] = 32;
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
    int sideAnimation = 0; // 178 é a barra
    while(1==1)
    {        
        gotoxy(0, 0);
        sideAnimation = sideAnimation == 0 ? 1 : 0;  
        printMatrix(matrix, sideAnimation);
        CLEAR_SCREEN;
    }
}