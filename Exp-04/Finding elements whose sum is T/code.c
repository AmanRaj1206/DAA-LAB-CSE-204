#include <stdio.h>

#define SIZE 100

struct HashMap
{
    int table[SIZE];
};

void initialize(struct HashMap *h)
{
    for (int i = 0; i < SIZE; i++)
        h->table[i] = 0;
}

void insert(struct HashMap *h, int value)
{
    if (value >= 0 && value < SIZE)
        h->table[value]++;
}

int search(struct HashMap *h, int value)
{
    if (value >= 0 && value < SIZE && h->table[value] > 0)
        return 1;

    return 0;
}

void findPairs(struct HashMap *h, int Arr[], int n, int T)
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        int complement = T - Arr[i];

        // 1. Check if the required complement was seen PREVIOUSLY
        if (search(h, complement))
        {
            printf("Pair found: %d + %d = %d\n", Arr[i], complement, T);
            found = 1;
        }

        // 2. Insert current element AFTER searching
        insert(h, Arr[i]);
    }

    if (!found)
        printf("No pair found\n");
}

int main()
{
    struct HashMap h;
    int Arr[SIZE];
    int n, T;

    initialize(&h);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter target value T: ");
    scanf("%d", &T);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
        // Do NOT call insert here! Insert inside findPairs instead.
    }

    findPairs(&h, Arr, n, T);

    return 0;
}
