#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[3][3]) 
{
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  ---+---+---\n");
    printf("1  %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verificarVitoria(char tabuleiro[3][3], char jogador) 
{
    // Verifica linhas
    for (int i = 0; i < 3; i++) 
    {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) 
        {
            return 1;
        }
    }
  
    // Verifica colunas
    for (int j = 0; j < 3; j++) 
    {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) 
        {
            return 1;
        }
    }
  
    // Verifica diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) 
    {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) 
    {
        return 1;
    }
    return 0;
}

int main() 
{
    char tabuleiro[3][3] = 
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int jogadorAtual = 1;
    int jogadas = 0;
    int linha, coluna;

    while (jogadas < 9) 
    {
        imprimirTabuleiro(tabuleiro);
        printf("Vez do jogador %d (digite linha coluna): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') 
        {
            printf("Jogada inválida, tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual == 1 ? 'X' : 'O';

        if (verificarVitoria(tabuleiro, tabuleiro[linha][coluna])) 
        {
            printf("Jogador %d venceu!\n", jogadorAtual);
            imprimirTabuleiro(tabuleiro);
            return 0;
        }

        jogadorAtual = jogadorAtual == 1 ? 2 : 1;
        jogadas++;
    }

    printf("Empate!\n");
    imprimirTabuleiro(tabuleiro);
    return 0;
}
