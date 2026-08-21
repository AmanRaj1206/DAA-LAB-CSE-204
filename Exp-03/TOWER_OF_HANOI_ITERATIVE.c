#include <stdio.h>
#include <math.h>

#define MAX 100

int stackA[MAX], stackB[MAX], stackC[MAX];
int topA = -1, topB = -1, topC = -1;

void push(int stack[], int *top, int value)
{
    stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
    return stack[(*top)--];
}

int peek(int stack[], int top)
{
    if (top == -1)
        return MAX + 1;

    return stack[top];
}

void moveDisk(char from, char to, int stackFrom[], int *topFrom,
              int stackTo[], int *topTo)
{
    int disk = pop(stackFrom, topFrom);
    push(stackTo, topTo, disk);

    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void legalMove(char rod1, char rod2, int stack1[], int *top1,
               int stack2[], int *top2)
{
    int disk1 = peek(stack1, *top1);
    int disk2 = peek(stack2, *top2);

    if (disk1 < disk2)
        moveDisk(rod1, rod2, stack1, top1, stack2, top2);
    else
        moveDisk(rod2, rod1, stack2, top2, stack1, top1);
}

int main()
{
    int n;
    int totalMoves;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--)
    {
        push(stackA, &topA, i);
    }

    totalMoves = pow(2, n) - 1;

    if (n % 2 == 0)
    {
        for (int i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                legalMove('A', 'B', stackA, &topA, stackB, &topB);
            else if (i % 3 == 2)
                legalMove('A', 'C', stackA, &topA, stackC, &topC);
            else
                legalMove('B', 'C', stackB, &topB, stackC, &topC);
        }
    }
    else
    {
        for (int i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                legalMove('A', 'C', stackA, &topA, stackC, &topC);
            else if (i % 3 == 2)
                legalMove('A', 'B', stackA, &topA, stackB, &topB);
            else
                legalMove('B', 'C', stackB, &topB, stackC, &topC);
        }
    }

    return 0;
}
