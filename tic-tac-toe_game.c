#include <stdio.h>

void printBoard(char board[3][3]) 
{
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("1  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char board[3][3], char player) 
{
    // Check rows
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) 
        {
            return 1;
        }
    }
  
    // Check columns
    for (int j = 0; j < 3; j++) 
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) 
        {
            return 1;
        }
    }
  
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
    {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
    {
        return 1;
    }
    return 0;
}

int main() 
{
    char board[3][3] = 
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int currentPlayer = 1;
    int moves = 0;
    int row, col;
    while (moves < 9) 
    {
        printBoard(board);
        printf("Player %d's turn (enter row column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') 
        {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = currentPlayer == 1 ? 'X' : 'O';
        if (checkWin(board, board[row][col])) 
        {
            printf("Player %d wins!\n", currentPlayer);
            printBoard(board);
            return 0;
        }
        currentPlayer = currentPlayer == 1 ? 2 : 1;
        moves++;
    }
    printf("Tie game!\n");
    printBoard(board);
    return 0;
}
