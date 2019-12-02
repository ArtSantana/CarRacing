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
    RelampagoMarquinhos->laterais = 21;
    RelampagoMarquinhos->ladoTela = 0;
}

void initEnemy(car *Enemy)
{
    Enemy->trackingLinha = 0;
    int side = rand() % 10;
    if(side % 2 == 0) Enemy->ponta = 10;
    else Enemy->ponta = 4;
}

void putCarOnMatrix(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos)
{
    matrix[RelampagoMarquinhos->laterais][RelampagoMarquinhos->ponta] = BOX; // PONTA
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta] = BOX; // MEIO
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-1] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-2] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+1] = BOX;
    matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+2] = BOX;
    matrix[RelampagoMarquinhos->laterais+2][RelampagoMarquinhos->ponta] = BOX; // Solitario
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-1] = BOX; // bundinha
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-2] = BOX; // bundinha
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+1] = BOX; // bundinha
    matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+2] = BOX; // bundinha
}

void putEnemyOnMatrix(char matrix[ROWS][COLUMN], car *Enemy)
{    
    // 4 IF'S - // 24 Ponto mais baixo - // 0 Ponto mais alto
    if(Enemy->trackingLinha == 0)
    {
        matrix[Enemy->trackingLinha][Enemy->ponta-1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta-2] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+2] = BOX; // bundinha        
    }
    else if(Enemy->trackingLinha == 1)
    {
        // Apagando
        matrix[Enemy->trackingLinha-1][Enemy->ponta-1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta-2] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+2] = SPACE; // bundinha        
        //
        matrix[Enemy->trackingLinha-1][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha][Enemy->ponta-1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta-2] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+2] = BOX; // bundinha
    }
    else if(Enemy->trackingLinha == 2)
    {
        // Apagando
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta-1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta-2] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+2] = SPACE; // bundinha
        //
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha][Enemy->ponta-1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta-2] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+2] = BOX; // bundinha
    }
    else if(Enemy->trackingLinha == 3)
    {
        // Apagando
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta-1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta-2] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+2] = SPACE; // bundinha
        //
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = BOX; // ponta
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha][Enemy->ponta-1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta-2] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+2] = BOX; // bundinha    
    }
    
    else if(Enemy->trackingLinha < 25)
    {
        // Apagando
        matrix[Enemy->trackingLinha-4][Enemy->ponta] = SPACE; // ponta
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta-1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta-2] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+2] = SPACE; // bundinha    

        //
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = BOX; // ponta
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha][Enemy->ponta-1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta-2] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+1] = BOX; // bundinha
        matrix[Enemy->trackingLinha][Enemy->ponta+2] = BOX; // bundinha    
    }

    else if(Enemy->trackingLinha == 25)
    {
        // Apagando
        matrix[Enemy->trackingLinha-4][Enemy->ponta] = SPACE; // ponta
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta-1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta-2] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+1] = SPACE; // bundinha
        matrix[Enemy->trackingLinha-1][Enemy->ponta+2] = SPACE; // bundinha    
        //        
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = BOX; // ponta
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 1] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 2] = BOX; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = BOX; // solitario
        matrix[Enemy->trackingLinha-1][Enemy->ponta] = BOX; // solitario        
    }
    else if(Enemy->trackingLinha == 26)
    {
        matrix[Enemy->trackingLinha-4][Enemy->ponta] = SPACE; // ponta
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 1] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 2] = SPACE; // solitario
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = SPACE; // solitario
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = SPACE; // solitario        
        //
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = BOX; // ponta
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 1] = BOX; // medio
        matrix[Enemy->trackingLinha-2][Enemy->ponta - 2] = BOX; // medio
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 1] = BOX; // medio
        matrix[Enemy->trackingLinha-2][Enemy->ponta + 2] = BOX; // medio
        matrix[Enemy->trackingLinha-2][Enemy->ponta] = BOX; // medio      
    }
    else if(Enemy->trackingLinha == 27)
    {
        matrix[Enemy->trackingLinha-4][Enemy->ponta] = SPACE; // ponta
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = SPACE; // medio
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 1] = SPACE; // medio
        matrix[Enemy->trackingLinha-3][Enemy->ponta - 2] = SPACE; // medio
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 1] = SPACE; // medio
        matrix[Enemy->trackingLinha-3][Enemy->ponta + 2] = SPACE; // medio
        //
        matrix[Enemy->trackingLinha-3][Enemy->ponta] = BOX; // ponta        
        
    }
    else if(Enemy->trackingLinha == 28)
    {
        matrix[Enemy->trackingLinha-4][Enemy->ponta] = SPACE; // ponta        
    }    
}

void movimentMarquinhos(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos, int key)
{
    switch(key)
    {
        case (int)'d':
        case (int)'D':
        case RIGHT:
            matrix[RelampagoMarquinhos->laterais][RelampagoMarquinhos->ponta] = SPACE; // PONTA
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta] = SPACE; // MEIO
            matrix[RelampagoMarquinhos->laterais+2][RelampagoMarquinhos->ponta] = SPACE; // MEIO
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+2] = SPACE;
            RelampagoMarquinhos->ponta = 10;
            break;
        case (int)'a':
        case (int)'A':
        case LEFT:
            matrix[RelampagoMarquinhos->laterais][RelampagoMarquinhos->ponta] = SPACE; // PONTA
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta] = SPACE; // MEIO
            matrix[RelampagoMarquinhos->laterais+2][RelampagoMarquinhos->ponta] = SPACE; // MEIO
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta-2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+1][RelampagoMarquinhos->ponta+2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta-2] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+1] = SPACE;
            matrix[RelampagoMarquinhos->laterais+3][RelampagoMarquinhos->ponta+2] = SPACE;
            RelampagoMarquinhos->ponta = 4;
            break;
    }
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
                        matrix[i][COLUMN - 2] = BOX;
                    }
                }

                printf("%c", matrix[i][j]);                
            }
            printf("\n");
        }        
    
}

void runtime(char matrix[ROWS][COLUMN], car *RelampagoMarquinhos, car *Enemy)
{
    int sideAnimation = 0, keyPressed = 0;
    while(keyPressed != ESC)
    {        
        gotoxy(0, 0);

        keyPressed = 43;

        if(kbhit()) keyPressed = getch(); // PEGANDO A DIREÇÃO

        if(kbhit() == ARROWS) keyPressed = getch(); // SE FOR ARROW PRECISA PEGAR DUAS VEZES.

        movimentMarquinhos(matrix, RelampagoMarquinhos, keyPressed);

        putCarOnMatrix(matrix, RelampagoMarquinhos);
        putEnemyOnMatrix(matrix, Enemy);

        sideAnimation = sideAnimation == 0 ? 1 : 0;
        printMatrix(matrix, sideAnimation);

        Enemy->trackingLinha += 1;
        if(Enemy->trackingLinha == 29)
        {
            int side = rand() % 10;
            if(side % 2 == 0) Enemy->ponta = 10;
            else Enemy->ponta = 4;
            Enemy->trackingLinha = 0;
        } 

        CLEAR_SCREEN;
    }
}