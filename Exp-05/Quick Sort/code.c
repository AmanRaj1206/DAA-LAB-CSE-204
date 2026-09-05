#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int Arr[], int low, int high)
{
    int pivot = Arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (Arr[j] < pivot)
        {
            i++;
            swap(&Arr[i], &Arr[j]);
        }
    }

    swap(&Arr[i + 1], &Arr[high]);

    return i + 1;
}

void quickSort(int Arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(Arr, low, high);

        quickSort(Arr, low, p - 1);
        quickSort(Arr, p + 1, high);
    }
}

int main()
{
    int n, Arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &Arr[i]);

    quickSort(Arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);

    return 0;
}
