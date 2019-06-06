#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
//----------------------------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//--------------------------------------------------------------------------------------------------------------------------------
main(){

    char tecla;
    int l=1, c=1;
    system("cls");
    printf("Para sair precione 'ESC'\n");
    printf("W, S, A, D, movimentam o personagem\n");
    printf("%c = Parede %c = Caixa %c = Boneco \n\n",178, 219, 6);
    printf("PRIMEIRA FASE\n");
    system("pause");

    //mapa que vai ser comparado, comparacao com numeros sao mais faceis
    char mapa1[9][9]={{1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,0,2,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1}};
    //mapa que vai ser printado
    char mapa1tela[9][9]={{178,178,178,178,178,178,178,178,178},{178,' ',' ',' ',' ',' ',' ',' ',178},{178,' ',' ',' ',' ',' ',' ',' ',178},
                          {178,' ',' ',' ',' ',' ',' ',' ',178},{178,' ',' ',' ',' ',' ',' ',' ',178},{178,' ','O',' ',' ',' ',' ',' ',178},
                          {178,' ',' ',' ',' ',' ',' ',' ',178},{178,' ',' ',' ',' ',' ',' ',' ',178},{178,178,178,178,178,178,178,178,178}};
    system("cls");
    for(int il = 0; il<9; il++){
        for(int ic =0; ic<9; ic++){
            printf("%c", mapa1tela[il][ic]);
        }
        printf("\n");
    }


    do{
        gotoxy(c,l);
        printf("%c",6);
        tecla=getch();
        switch(tecla){
            case 'w':
                if (mapa1[l-1][c] != 1 ){
                    if(mapa1[l-1][c] == 2 ){
                        if(mapa1[l-2][c] != 1 ){
                            mapa1[l-2][c]=2;
                            mapa1[l-1][c]=0;
                            mapa1tela[l-2][c]='O';
                            mapa1tela[l-1][c]=' ';
                        }
                    }
                    l--;
                }
            break;
            case 's':
                if (mapa1[l+1][c] != 1 ){
                    if(mapa1[l+1][c] == 2 ){
                        if(mapa1[l+2][c] != 1 ){
                            mapa1[l+2][c]=2;
                            mapa1[l+1][c]=0;
                            mapa1tela[l+2][c]='O';
                            mapa1tela[l+1][c]=' ';
                        }
                    }
                    l++;
                }
            break;
            case 'a':
                if (mapa1[l][c-1] != 1 ){
                    if(mapa1[l][c-1] == 2 ){
                        if(mapa1[l][c-2] != 1 ){
                            mapa1[l][c-2]=2;
                            mapa1[l][c-1]=0;
                            mapa1tela[l][c-2]='O';
                            mapa1tela[l][c-1]=' ';
                        }
                    }
                    c--;
                }
            break;
            case 'd':
                if (mapa1[l][c+1] != 1 ){
                    if(mapa1[l][c+1] == 2 ){
                        if(mapa1[l][c+2] != 1 ){
                            mapa1[l][c+2]=2;
                            mapa1[l][c+1]=0;
                            mapa1tela[l][c+2]='O';
                            mapa1tela[l][c+1]=' ';
                        }
                    }
                    c++;
                }
            break;
        }
        system("cls");
        for(int il = 0; il<9; il++){
            for(int ic =0; ic<9; ic++){
                printf("%c", mapa1tela[il][ic]);
            }
            printf("\n");
        }
    }
    while(tecla!=13);
}
