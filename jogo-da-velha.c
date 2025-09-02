#include <stdio.h>
#include <stdlib.h>

void imprime_tabuleiro(char tabuleiro[3][3])
{
    system("clear");
    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    return;
}

int main()
{
    char tabuleiro[3][3], jogador;
    int i, j, linha, coluna, rondada, ganhou;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

    imprime_tabuleiro(tabuleiro);

    ganhou = 0;

    for (rondada = 1; rondada <= 9 && ganhou == 0; rondada++)
    {
        if (rondada % 2 == 1)
        {
            jogador = "X";
        }
        else
        {
            jogador = "O";
        }

        do
        {
            printf("Digite as coordenadas (de 1 a 3) em que quer colocar o '%c': ", jogador);
            scanf("%d %d", &linha, &coluna);
        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ');
    }
}