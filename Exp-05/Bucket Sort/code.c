#include <stdio.h>

void Sort(int bucket[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int Arr[], int n)
{
    int max = Arr[0];

    for (int i = 1; i < n; i++)
    {
        if (Arr[i] > max)
            max = Arr[i];
    }

    int bucket[10][100] = {0};
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = (Arr[i] * 10) / (max + 1);
        bucket[index][count[index]++] = Arr[i];
    }

    for (int i = 0; i < 10; i++)
        Sort(bucket[i], count[i]);

    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i]; j++)
            Arr[k++] = bucket[i][j];
    }
}

int main()
{
    int n, Arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d non-negative elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &Arr[i]);

    bucketSort(Arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);

    return 0;
}
