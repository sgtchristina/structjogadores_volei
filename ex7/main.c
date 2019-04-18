#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*7) Fa�a um programa utilizando struct para cadastrar os jogadores de um time de v�lei.
Os dados que devem ser cadastrados s�o: nome, idade, posi��o e n�mero da camisa.
Voc� deve utilizar uma estrutura para armazena pelo menos 6 jogadores titulares
e outra estrutura para armazenar pelo menos 4jogadores reserva.
Fa�a um menu que permita cadastrar os jogadores e tamb�m emitir relat�rios dos titulares e dos reservas.*/
struct jogador
{
    char nome[100];
    int idade;
    char posicao[20];
    int numcamisa;
};

struct jogador *CadastraJogadores(int minimo);

void MostraJogadores(struct jogador *Jogadores, int minimo);

int qtd, qtd_t, qtd_r, i;

int main()
{
    int opc;

    struct jogador *Titulares;

    struct jogador *Reservas;

    do
    {
        printf("\n\n1 - Cadastrar Titulares ");
        printf("\n\n2 - Cadastrar Reservas");
        printf("\n\n3 - Relat�rio Titulares");
        printf("\n\n4 - Relat�rio Reservas");
        printf("\n\n5 - Sair do Programa\n\n");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                printf("\n\nCADASTRANDO TITULARES\n\n");
                if (Titulares != NULL)
                {

                    free(Titulares);
                    printf("\n\nRESERVAS");
                }
                Titulares = CadastraJogadores(6);
                break;
            case 2:
                printf("\n\nCADASTRANDO RESERVAS\n\n");
                /*if (Reservas != NULL)
                {

                     free(Reservas);
                     printf("\n\nRESERVAS");
                }*/

                Reservas = CadastraJogadores(4);
                break;
            case 3: //relatorio titulares
                MostraJogadores(Titulares, 6);
            break;
            case 4:
                MostraJogadores(Reservas, 4);
            break;
            case 5:
                if (Titulares != NULL)
                    free(Titulares);
                if (Reservas != NULL)
                    free(Reservas);
            default:
                printf("\nOp��o inv�lida\n");
        }
    }while (opc!=4);

    return 0;
}

struct jogador *CadastraJogadores(int minimo)
{
    struct jogador *Jogadores;
    do
    {
        printf("Quantos Jogadores voc� deseja cadastrar(m�nimo %d)? ", minimo);
        scanf("%d", &qtd);
        fflush(stdin);
    }while(qtd<minimo);

    if (minimo == 6)
        qtd_t = qtd;
    else
        qtd_r = qtd;

    if (!(Jogadores = (struct jogador *)malloc(qtd * sizeof(struct jogador))))
    {
        printf("N�o foi poss�vel alocar os Jogadores\n");
        exit(0);
    }

    for(i=0; i<qtd; i++)
    {
        printf("\n\nDigite o nome %d: ", i+1);
        gets(Jogadores[i].nome);

        printf("\n\nDigite a idade %d: ", i+1);
        scanf("%d", &Jogadores[i].idade);
        fflush(stdin);

        printf("\n\nDigite a posi��o %d: " , i+1);
        gets(Jogadores[i].posicao);

        printf("\n\nDigite o n�mero da camisa %d: ", i+1);
        scanf("%d", &Jogadores[i].numcamisa);
        fflush(stdin);
    }

    return(Jogadores);
}

void MostraJogadores(struct jogador *Jogadores, int minimo)
{
    if (minimo == 6)
        qtd = qtd_t;
    else
        qtd = qtd_r;

    for(i=0; i<qtd; i++)
    {
        printf("\n\nJogador %d:", i+1);
        printf("%s\n\nNome: ", Jogadores[i].nome);
        printf("%d\n\nIdade: ", Jogadores[i].idade);
        printf("%s\n\nPosicao: ", Jogadores[i].posicao);
        printf("%d\n\nNumero da camisa: ", Jogadores[i].numcamisa);
    }
}

