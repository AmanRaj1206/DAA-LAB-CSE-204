#include <stdio.h>

void merge(int Arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (Arr[i] <= Arr[j])
            temp[k++] = Arr[i++];
        else
            temp[k++] = Arr[j++];
    }

    while (i <= mid)
        temp[k++] = Arr[i++];

    while (j <= high)
        temp[k++] = Arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        Arr[i] = temp[k];
}

void mergeSort(int Arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(Arr, low, mid);
        mergeSort(Arr, mid + 1, high);
        merge(Arr, low, mid, high);
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

    mergeSort(Arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);

    return 0;
}
