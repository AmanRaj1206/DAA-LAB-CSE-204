#include <stdio.h>
#include <stdlib.h>

int count = 0;

int isSafe(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int board[], int n)
{
    count++;
    printf("\nSolution %d:\n", count);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solveNQueen(int board[], int row, int n)
{
    if (row == n)
    {
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            solveNQueen(board, row + 1, n);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int board[n];

    solveNQueen(board, 0, n);

    if (count == 0)
        printf("No solution exists\n");
    else
        printf("\nTotal solutions: %d\n", count);

    return 0;
}
