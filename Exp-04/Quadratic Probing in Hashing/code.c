#include <stdio.h>

#define SIZE 10

int main()
{
    int hashTable[SIZE];
    int n, value, index, j;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        j = 0;
        index = value % SIZE;

        while (hashTable[index] != -1)
        {
            j++;
            index = (value % SIZE + j * j) % SIZE;
        }

        hashTable[index] = value;
    }

    printf("Hash Table using Quadratic Probing:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("[%d] : Empty\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }

    return 0;
}
