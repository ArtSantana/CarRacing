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

void initCar(car *RelampagoMarquinhos)
{
    RelampagoMarquinhos->ponta = 4;
    RelampagoMarquinhos->laterais = 20;
    RelampagoMarquinhos->ladoTela = 0;
}

void putCarOnMatrix(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos)
{
    matrix[RelampagoMarquinhos->laterais][RelampagoMarquinhos->ponta] = BOX; // PONTA
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta] = BOX; // MEIO
    matrix[RelampagoMarquinhos->laterais+2][RelampagoMarquinhos->ponta] = BOX; // MEIO
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-1] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-2] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+1] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+2] = BOX;
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-1] = BOX;
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-2] = BOX;
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+1] = BOX;
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+2] = BOX;
}

void printMatrix(char matrix[ROWS][COLUMN], int sideAnimation)
{
    int i, j, k;

    for(i=0; i<ROWS; i++)
        {            
            printf("\t\t\t\t\t\t"); // Centralizando a pista no terminal
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
                        matrix[i][1] = BOX;
                        matrix[i][COLUMN -2] = BOX;
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
                        matrix[i][1] = BOX;
                        matrix[i][COLUMN -2] = BOX;
                    }
                }

                printf("%c", matrix[i][j]);                
            }
            printf("\n");
        }
    
}

void runtime(char matrix[ROWS][COLUMN])
{
    int sideAnimation = 0;
    while(1==1)
    {        
        gotoxy(0, 0);
        sideAnimation = sideAnimation == 0 ? 1 : 0;  
        printMatrix(matrix, sideAnimation);
        CLEAR_SCREEN;
    }
}