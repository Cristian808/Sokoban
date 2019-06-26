#include <stdio.h>
#include <conio.h>
#include <windows.h>

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
    printf("Para sair precione '1'\n");
    printf("W, S, A, D, movimentam o personagem\n");
    printf("%c = Parede %c = Caixa %c = Boneco \n\n",178, 219, 6);
    system("pause");
    int m=1; //indica fase q esta
    int caixa=0; //conta quantas caixas tem no mapa
    int cont=0; //conta se o mapa ja foi atualizado
    int mapa[9][9];
    int mapatela[9][9];

    //mapa que vai ser comparado, comparacao com numeros sao mais faceis
    int mapa1[9][9]={{1,1,1,1,1,1,1,1,1},
                      {1,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,2,0,3,1},
                      {1,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,2,0,1},
                      {1,3,2,0,0,0,3,0,1},
                      {1,1,1,1,1,1,1,1,1}};

    int mapa2[9][9]={{1,1,1,1,1,1,1,1,1},
                      {1,0,0,0,0,1,0,3,1},
                      {1,0,0,1,0,1,0,0,1},
                      {1,0,0,0,2,3,0,2,1},
                      {1,0,1,1,0,1,0,0,1},
                      {1,0,3,1,0,0,0,1,1},
                      {1,1,2,0,0,0,1,1,1},
                      {1,1,0,0,0,0,1,1,1},
                      {1,1,1,1,1,1,1,1,1}};

    int mapa3[9][9]={ {1,1,1,1,1,1,1,1,1},
                      {1,0,0,0,1,0,0,0,1},
                      {1,0,0,0,1,2,0,0,1},
                      {1,0,0,0,1,3,0,0,1},
                      {1,1,1,0,1,1,0,1,1},
                      {1,0,0,0,1,0,3,0,1},
                      {1,0,0,0,1,0,2,1,1},
                      {1,0,0,0,2,0,0,3,1},
                      {1,1,1,1,1,1,1,1,1}};

    //mapa que vai ser printado
    int mapa1tela[9][9]={{178,178,178,178,178,178,178,178,178},
                     {178,0,0,0,0,0,0,0,178},
                     {178,0,0,0,0,2,0,220,178},
                     {178,0,0,0,0,0,0,0,178},
                     {178,0,0,0,0,0,0,0,178},
                     {178,0,0,0,0,0,0,0,178},
                     {178,0,0,0,0,0,2,0,178},
                     {178,220,2,0,0,0,220,0,178},
                     {178,178,178,178,178,178,178,178,178}};

    int mapa2tela[9][9]={{178,178,178,178,178,178,178,178,178},
                       {178,0,0,0,0,178,0,220,178},
                       {178,0,0,178,0,178,0,0,178},
                       {178,0,0,0,2,220,0,2,178},
                       {178,0,178,178,0,178,0,0,178},
                       {178,0,220,178,0,0,0,178,178},
                       {178,178,2,0,0,0,178,178,178},
                       {178,178,0,0,0,0,178,178,178},
                       {178,178,178,178,178,178,178,178,178}};

    int mapa3tela[9][9]={ {178,178,178,178,178,178,178,178,178},
                      {178,0,0,0,178,0,0,0,178},
                      {178,0,0,0,178,2,0,0,178},
                      {178,0,0,0,178,220,0,0,178},
                      {178,178,178,0,178,178,0,178,178},
                      {178,0,0,0,178,0,220,0,178},
                      {178,0,0,0,178,0,2,178,178},
                      {178,0,0,0,2,0,0,220,178},
                      {178,178,178,178,178,178,178,178,178}};

    if(m==1){
        for(int il = 0; il<9; il++){
            for(int ic =0; ic<9; ic++){
                mapatela[il][ic]=mapa1tela[il][ic];
                mapa[il][ic]=mapa1[il][ic];
            }
        }
    }

    system("cls");
    for(int il = 0; il<9; il++){
        for(int ic =0; ic<9; ic++){
            printf("%c", mapatela[il][ic]);
        }
        printf("\n");
    }


    do{
        gotoxy(c,l);
        printf("%c",6);
        tecla=getch();
        switch(tecla){
            case 'w':
                if (mapa[l-1][c] != 1 && mapa[l-1][c] != 4){
                    if(mapa[l-1][c] == 2 ){
                        if(mapa[l-2][c] != 1 && mapa[l-2][c] != 4 && mapa[l-2][c] != 2){
                            if(mapa[l-2][c] == 3){
                                mapa[l-2][c]=4;
                                mapa[l-1][c]=0;
                                mapatela[l-2][c]=2;
                                mapatela[l-1][c]=0;
                            }
                            else{
                                mapa[l-2][c]=2;
                                mapa[l-1][c]=0;
                                mapatela[l-2][c]=2;
                                mapatela[l-1][c]=0;
                            }
                        }
                        else{
                            l++;
                        }
                    }
                    l--;
                }
            break;
            case 's':
                if (mapa[l+1][c] != 1 && mapa[l+1][c] != 4 ){
                    if(mapa[l+1][c] == 2 ){
                        if(mapa[l+2][c] != 1 && mapa[l+2][c] != 4 && mapa[l+2][c] != 2){
                            if(mapa[l+2][c] == 3){
                                mapa[l+2][c]=4;
                                mapa[l+1][c]=0;
                                mapatela[l+2][c]=2;
                                mapatela[l+1][c]=0;
                            }
                            else{
                                mapa[l+2][c]=2;
                                mapa[l+1][c]=0;
                                mapatela[l+2][c]=2;
                                mapatela[l+1][c]=0;
                            }
                        }
                        else{
                            l--;
                        }
                    }
                    l++;
                }
            break;
            case 'a':
                if (mapa[l][c-1] != 1 && mapa[l][c-1] != 4){
                    if(mapa[l][c-1] == 2 ){
                        if(mapa[l][c-2] != 1 && mapa[l][c-2] != 4 && mapa[l][c-2] != 2){
                            if(mapa[l][c-2] == 3){
                                mapa[l][c-2]=4;
                                mapa[l][c-1]=0;
                                mapatela[l][c-2]=2;
                                mapatela[l][c-1]=0;
                            }
                            else{
                                mapa[l][c-2]=2;
                                mapa[l][c-1]=0;
                                mapatela[l][c-2]=2;
                                mapatela[l][c-1]=0;
                            }
                        }
                        else{
                            c++;
                        }
                    }
                    c--;
                }
            break;
            case 'd':
                if (mapa[l][c+1] != 1 && mapa[l][c+1] != 4){
                    if(mapa[l][c+1] == 2 ){
                        if(mapa[l][c+2] != 1 && mapa[l][c+2] != 4 && mapa[l][c+2] != 2){
                            if(mapa[l][c+2] == 3){
                                mapa[l][c+2]=4;
                                mapa[l][c+1]=0;
                                mapatela[l][c+2]=2;
                                mapatela[l][c+1]=0;
                            }
                            else{
                                mapa[l][c+2]=2;
                                mapa[l][c+1]=0;
                                mapatela[l][c+2]=2;
                                mapatela[l][c+1]=0;
                            }
                        }
                        else{
                            c--;
                        }
                    }
                    c++;
                }
            break;
            case '1':
                return 0;
            break;
        }

        caixa=0;
        for(int il = 0; il<9; il++){
            for(int ic =0; ic<9; ic++){
                if(mapa[il][ic] == 2){ //se houver alguma caixa fora do ponto ele vai add um no contador de caixas
                    caixa++;
                }
            }
        }
        if(caixa==0){  //se nao tiver caixa no mapa ele vai passar o nivel
            m++;
            cont=0;
        }

        if(m==2 && cont==0){
            l=1;
            c=1;
            for(int il = 0; il<9; il++){
                for(int ic =0; ic<9; ic++){
                    mapatela[il][ic]=mapa2tela[il][ic];
                    mapa[il][ic]=mapa2[il][ic];
                }
            }
            cont++;
        }
        if(m==3 && cont==0){
            l=1;
            c=1;
            for(int il = 0; il<9; il++){
                for(int ic =0; ic<9; ic++){
                    mapatela[il][ic]=mapa3tela[il][ic];
                    mapa[il][ic]=mapa3[il][ic];
                }
            }
            cont++;
        }
        if(m==4){
            system("cls");
            printf("PARABENS VOCE CONCLUIU ESTE GRANDE E BELISSIMO GAME\n");
            system("pause");
            break;
        }

        if(m!=4){
            system("cls");
            for(int il = 0; il<9; il++){
                for(int ic =0; ic<9; ic++){
                    printf("%c", mapatela[il][ic]);
                }
                printf("\n");
            }
        }
    }
    while(tecla!=13);
}
