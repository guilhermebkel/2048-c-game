#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LIN 4
#define MAX_COL 4

//Funcao que move e soma as peÃ§as
void movePeca (int tabuleiro[4][4])
{
    int aux;
    char x;
    int i, j, z, y;

        //Imprime na tela um esboÃ§o do jogo
        printf("   JOGO 2048\n");
        printf("\n");
        for (i = 0; i < MAX_LIN; i++) {
                for(j = 0; j < MAX_COL; j++)
                        printf("%d    ", tabuleiro[i][j]);
                printf("\n");
                printf("\n");
                printf("\n");
    }
    scanf("%c", &x);
    getchar();

    if(x!='D' && x!='E' && x!='B' && x!='C' && x!='R' && x!='G')
    {
        do{
            system("clear");

            printf("Letra invalida\n");
            printf("-----------------\n");
            printf("(D)Leva pra direita\n");
            printf("(E)Leva pra esquerda\n");
            printf("(C)Leva pra cima\n");
            printf("(B)Leva pra baixo\n");
            printf("(R)Recomeca a partida\n");
            printf("------------------\n");
            printf("Digite (Q) para continuar o jogo: ");

            scanf("%c", &x);
            getchar();
        }while(x!='Q');
    }

    //Joga todos os numero para Direita
    if(x=='D')
    {
        for(i=0;i<4;i++)
        {
            //Soma das peÃ§as
            for(z=3;z>0;z--)
            {
                for(j=2;j>-1;j--)
                {
                    if(z==j)
                    {
                        j=z--;
                    }
                    if(j==0)
                    {
                        if (tabuleiro[i][z]==tabuleiro[i][j] && tabuleiro[i][2]==0 && tabuleiro[i][1]==0)
                        {
                            tabuleiro[i][z]=tabuleiro[i][j]+ tabuleiro[i][z];
                            tabuleiro[i][j]=0;
                        }
                    }
                    if(j==1)
                    {
                        if (tabuleiro[i][z]==tabuleiro[i][j] && tabuleiro[i][2]==0)
                        {
                            tabuleiro[i][z]=tabuleiro[i][j]+ tabuleiro[i][z];
                            tabuleiro[i][j]=0;
                        }
                    }
                }
            }
            //Soma das peÃ§as (adicional)
            for(z=3, j=2;z>0;z--, j--)
            {
                if(tabuleiro[i][z]==tabuleiro[i][j])
                {
                    tabuleiro[i][z]+=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //MovimentaÃ§Ã£o
            for(j=0,z=1,y=2;j<3;j++,z++,y++)
            {
                if(y>3)
                {
                    break;
                }
                if (tabuleiro[i][j]!=0 && tabuleiro[i][z]!=0 && tabuleiro[i][y]!=0 && tabuleiro[i][3]==0)
                {
                    tabuleiro[i][3]=tabuleiro[i][y];
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
                if (tabuleiro[i][z]!=0 && tabuleiro[i][y]==0)
                {
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=0;
                }
                if (tabuleiro[i][z]!=0 && tabuleiro[i][j]!=0 && tabuleiro[i][y]==0)
                {
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=tabuleiro[i][y];
                    tabuleiro[i][y]=0;
                }
            }
            //MovimentaÃ§Ã£o (adicional)
            for(j=0, z=1;j<3;j++,z++)
            {
                if (tabuleiro[i][z]==0)
                    {
                        aux=tabuleiro[i][j];
                        tabuleiro[i][j]=tabuleiro[i][z];
                        tabuleiro[i][z]=aux;
                    }
            }
        }
    }

    //Joga todos os numeros para esquerda
    if(x=='E')
    {
        for(i=0;i<4;i++)
        {
          //Soma das peÃ§as
          for(z=0;z<3;z++)
            {
                for(j=1;j<4;j++)
                {
                    if(z==j)
                    {
                        j=z++;
                    }
                    if(j==3)
                    {
                        if (tabuleiro[i][z]==tabuleiro[i][j] && tabuleiro[i][1]==0 && tabuleiro[i][2]==0)
                        {
                            tabuleiro[i][z]=tabuleiro[i][j]+ tabuleiro[i][z];
                            tabuleiro[i][j]=0;
                        }
                    }
                    if(j==2)
                    {
                        if (tabuleiro[i][z]==tabuleiro[i][j] && tabuleiro[i][1]==0)
                        {
                            tabuleiro[i][z]=tabuleiro[i][j]+ tabuleiro[i][z];
                            tabuleiro[i][j]=0;
                        }
                    }
                }
            }
            //Soma das peÃ§as (adicional)
            for(z=0, j=1;z<3;z++, j++)
            {
                if(tabuleiro[i][z]==tabuleiro[i][j])
                {
                    tabuleiro[i][z]+=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //MovimentaÃ§Ã£o
            for(j=3,z=2,y=1;j>0;j--,z--,y--)
            {
                if(y<0)
                {
                    break;
                }
                if (tabuleiro[i][j]!=0 && tabuleiro[i][z]!=0 && tabuleiro[i][y]!=0 && tabuleiro[i][0]==0)
                {
                    tabuleiro[i][0]=tabuleiro[i][y];
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
                if (tabuleiro[i][z]!=0 && tabuleiro[i][y]==0)
                {
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=0;
                }
                if (tabuleiro[i][z]!=0 && tabuleiro[i][j]!=0 && tabuleiro[i][y]==0)
                {
                    tabuleiro[i][y]=tabuleiro[i][z];
                    tabuleiro[i][z]=tabuleiro[i][y];
                    tabuleiro[i][y]=0;
                }
            }
            //MovimentaÃ§Ã£o (adicional)
            for(j=3, z=2;j>0;j--,z--)
            {
                if (tabuleiro[i][z]==0)
                {
                    tabuleiro[i][z]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }

            }

        }
    }

    //Desce todos os numeros
    if(x=='B')
    {
        for(j=0;j<4;j++)
        {
            //Soma das peÃ§as
            for(z=3;z>0;z--)
            {
                for(i=2;i>-1;i--)
                {
                    if(z==i)
                    {
                        i=z--;
                    }
                    if(i==0)
                    {
                        if (tabuleiro[z][j]==tabuleiro[i][j] && tabuleiro[2][j]==0 && tabuleiro[1][j]==0)
                        {
                            tabuleiro[z][j]=tabuleiro[i][j]+ tabuleiro[z][j];
                            tabuleiro[i][j]=0;
                        }
                    }
                    if(i==1)
                    {
                        if (tabuleiro[z][j]==tabuleiro[i][j] && tabuleiro[2][j]==0)
                        {
                            tabuleiro[z][j]=tabuleiro[i][j]+ tabuleiro[z][j];
                            tabuleiro[i][j]=0;
                        }
                    }
                }
            }
            //Soma das peÃ§as (adicional)
            for(z=3, i=2;z>0;z--, i--)
            {
                if(tabuleiro[z][j]==tabuleiro[i][j])
                {
                    tabuleiro[z][j]+=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //MovimentaÃ§Ã£o
            for(i=0,z=1,y=2;i<3;i++,z++,y++)
            {
                if(y>3)
                {
                    break;
                }
                if (tabuleiro[i][j]!=0 && tabuleiro[z][j]!=0 && tabuleiro[y][j]!=0 && tabuleiro[3][j]==0)
                {
                    tabuleiro[3][j]=tabuleiro[y][j];
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
                if (tabuleiro[z][j]!=0 && tabuleiro[y][j]==0)
                {
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=0;
                }
                if (tabuleiro[z][j]!=0 && tabuleiro[i][j]!=0 && tabuleiro[y][j]==0)
                {
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //movimentaÃ§Ã£o (adicional)
            for(i=0, z=1;i<3;i++,z++)
            {
                if (tabuleiro[z][j]==0)
                    {
                        aux=tabuleiro[i][j];
                        tabuleiro[i][j]=tabuleiro[z][j];
                        tabuleiro[z][j]=aux;
                    }
            }
        }
    }

    //Sobe todos os numeros
    if(x=='C')
    {
        for(j=0;j<4;j++)
        {
          //Soma das peÃ§as
          for(z=0;z<3;z++)
            {
                for(i=1;i<4;i++)
                {
                    if(z==i)
                    {
                        i=z++;
                    }
                    if(i==3)
                    {
                        if (tabuleiro[z][j]==tabuleiro[i][j] && tabuleiro[2][j]==0 && tabuleiro[1][j]==0)
                        {
                            tabuleiro[z][j]=tabuleiro[i][j]+ tabuleiro[z][j];
                            tabuleiro[i][j]=0;
                        }
                    }
                    if(i==2)
                    {
                        if (tabuleiro[z][j]==tabuleiro[i][j] && tabuleiro[1][j]==0)
                        {
                            tabuleiro[z][j]=tabuleiro[i][j]+ tabuleiro[z][j];
                            tabuleiro[i][j]=0;
                        }
                    }
                }
            }
            //Soma das peÃ§as (adicional)
            for(z=0, i=1;z<3;z++, i++)
            {
                if(tabuleiro[z][j]==tabuleiro[i][j])
                {
                    tabuleiro[z][j]+=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //MovimentaÃ§Ã£o
            for(i=3,z=2,y=1;i>0;i--,z--,y--)
            {
                if(y<0)
                {
                    break;
                }
                if (tabuleiro[i][j]!=0 && tabuleiro[z][j]!=0 && tabuleiro[y][j]!=0 && tabuleiro[0][j]==0)
                {
                    tabuleiro[0][j]=tabuleiro[y][j];
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
                if (tabuleiro[z][j]!=0 && tabuleiro[y][j]==0)
                {
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=0;
                }
                if (tabuleiro[z][j]!=0 && tabuleiro[i][j]!=0 && tabuleiro[y][j]==0)
                {
                    tabuleiro[y][j]=tabuleiro[z][j];
                    tabuleiro[z][j]=tabuleiro[i][j];
                    tabuleiro[i][j]=0;
                }
            }
            //movimentaÃ§Ã£o (adicional)
            for(i=3, z=2;i>0;i--,z--)
            {
                if (tabuleiro[z][j]==0)
                    {
                        aux=tabuleiro[i][j];
                        tabuleiro[i][j]=tabuleiro[z][j];
                        tabuleiro[z][j]=aux;
                    }
            }
        }
    }

    //RecomeÃ§a a partida
    if(x=='R')
    {
        for (i = 0; i < MAX_LIN; i++)
        {
        	for (j = 0; j < MAX_COL; j++)
                        tabuleiro[i][j] = 0;
        }

        apareceNum(tabuleiro);
    }

    if(x=='G')
    {
        tabuleiro[3][3]=1024;
        tabuleiro[3][2]=1024;
    }
}


//Função que verifica se o jogador perdeu ou venceu
void verifVenPer (int tabuleiro[4][4])
{
    int i, j, a=0;
    char x;

    //Essa parte conta quantos numeros sao diferentes de 0
    for (i = 0; i < MAX_LIN; i++) {
                for(j = 0; j < MAX_COL; j++)
                {
                        if(tabuleiro[i][j]!=0)
                        {
                             a++;
                        }
                }
	}
	if (a<16)
    {
        a=0;
    }

    //Verifica se o jogador perdeu
    if(a>=16){
        system("clear");

                //Imprime na tela um esboço do jogo
                printf("   JOGO 2048\n");
                printf("\n");
                for (i = 0; i < MAX_LIN; i++) {
                    for(j = 0; j < MAX_COL; j++)
                        printf("%d    ", tabuleiro[i][j]);
                        printf("\n");
                        printf("\n");
                        printf("\n");
                }
                printf("Voce Perdeu! (Digite (Q) para sair ou (R) para recomecar o jogo: ");
                scanf("%c", &x);
                getchar();

                if (x=='R')
                {
                    for (i = 0; i < MAX_LIN; i++)
                    {
                        for (j = 0; j < MAX_COL; j++)
                        tabuleiro[i][j] = 0;
                    }
                    apareceNum(tabuleiro);
                }
                if (x=='Q')
                {
                    exit(0);
                }
                    system("clear");
    }

    //Verifica se o jogador venceu
    for (i = 0; i < MAX_LIN; i++)
    {
        for(j = 0; j < MAX_COL; j++)
        {
            if(tabuleiro[i][j]==2048)
            {
                system("clear");

                //Imprime na tela um esboço do jogo
                printf("   JOGO 2048\n");
                printf("\n");
                for (i = 0; i < MAX_LIN; i++) {
                    for(j = 0; j < MAX_COL; j++)
                        printf("%d    ", tabuleiro[i][j]);
                        printf("\n");
                        printf("\n");
                        printf("\n");
                }
                printf("Voce venceu!(Digite (Q) para sair ou (R) para recomecar o jogo: ");
                scanf("%c", &x);
                getchar();

                if (x=='R')
                {
                    for (i = 0; i < MAX_LIN; i++)
                    {
                        for (j = 0; j < MAX_COL; j++)
                        tabuleiro[i][j] = 0;
                    }
                    apareceNum(tabuleiro);
                }
                if (x=='Q')
                {
                    exit(a);
                }
                    system("clear");
                }
        }
    }
}

//Função que faz aparecer um numero novo
int apareceNum(int tabuleiro[4][4])
{
    srand( (unsigned)time(NULL) );

    int i, doisQuatro, linha, coluna;
    //Pega aleatoriamente 2 ou 4
    for(i=1;i>0;i++)
    {
        doisQuatro = 1+(rand()%4);
        if(doisQuatro==2)
        {
            break;
        }
        if(doisQuatro==4)
        {
            break;
        }
    }

    //Pega aleatoriamente um lugar do jogo para colocar 2 ou 4
	for(i=1;i>0;i++){
            linha = rand() % MAX_LIN;
            coluna = rand() % MAX_COL;

			if(tabuleiro[linha][coluna]==0)
			{
                tabuleiro[linha][coluna]=doisQuatro;
                break;
			}
	}
	system("clear");
}

int main()
{
    int tabuleiro[4][4];
	int i=0,j=0, a;

    srand( (unsigned)time(NULL) );

    //Coloca 0 para cada posição do jogo
    for (i = 0; i < MAX_LIN; i++)
	{
        	for (j = 0; j < MAX_COL; j++)
                        tabuleiro[i][j] = 0;
	}

    //função para aparecer 2 numeros de inicio
    for(i=0;i<2;i++)
    {
         apareceNum(tabuleiro);
    }

    //Aqui é onde o jogo todo acontece
do{
    movePeca(tabuleiro);
    verifVenPer(tabuleiro);
    apareceNum(tabuleiro);
}while(a);

return 0;
}
