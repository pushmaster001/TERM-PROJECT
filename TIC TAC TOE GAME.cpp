#include <stdio.h>
char board[3][3];
void initializeBoard() 
{
    int i, j;
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard() 
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
char checkWin() 
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];
    }
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}
int isBoardFull() 
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
int main()
{
    int row, col;
    int validMove;
    char currentPlayer = 'X';
    char winner = ' ';
    initializeBoard();
    do 
    {
        printBoard();
        printf("Player %c, enter your move (row and column: 0, 1, or 2): ", currentPlayer);
        scanf_s("%d %d", &row, &col);
        validMove = 1;
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            printf("Invalid position. Please use values 0, 1, or 2.\n");
            validMove = 0;
        }
        else if (board[row][col] != ' ')
        {
            printf("That cell is already taken. Please try another move.\n");
            validMove = 0;
        }
        if (validMove) 
        {
            board[row][col] = currentPlayer;
            winner = checkWin();
            if (winner != ' ') 
            {
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    while (!isBoardFull());
    printBoard();
    if (winner != ' ') {
        printf("Congratulations! Player %c wins!\n", winner);
    }
    else {
        printf("It's a draw!\n");
    }
    return 0;
}