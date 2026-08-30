#include <stdio.h>

#define SIZE 100

struct HashMap
{
    int table[SIZE];
};

void initialize(struct HashMap *h)
{
    for (int i = 0; i < SIZE; i++)
    {
        h->table[i] = 0;
    }
}

void insert(struct HashMap *h, int value)
{
    if (value >= 0 && value < SIZE)
    {
        h->table[value]++;
    }
}

void printFrequencies(struct HashMap *h, int Arr[], int n)
{
    printf("\nElement       Frequency\n");
   

    for (int i = 0; i < n; i++)
    {
        int element = Arr[i];

        // Print frequency only if this element hasn't been printed yet
        if (element >= 0 && element < SIZE && h->table[element] > 0)
        {
            printf("%3d      -> \t %d\n", element, h->table[element]);
            
            // Set to 0 so duplicate numbers in the array are skipped
            h->table[element] = 0;
        }
    }
}

void readInput(int Arr[], int *n)
{
    printf("Enter number of elements: ");
    scanf("%d", n);

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &Arr[i]);
    }
}

int main()
{
    struct HashMap h;
    int Arr[SIZE];
    int n;

    initialize(&h);
    readInput(Arr, &n);

    // Build frequency table
    for (int i = 0; i < n; i++)
    {
        insert(&h, Arr[i]);
    }

    // Display frequencies of distinct elements
    printFrequencies(&h, Arr, n);

    return 0;
}
