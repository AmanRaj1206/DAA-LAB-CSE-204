#include <stdio.h>

int binarySearch(int Arr[], int beg, int end, int key)
{
    if (beg <= end)
    {
        int mid = (beg + end) / 2;

        if (key == Arr[mid])
        {
            return mid;
        }
        else if (key < Arr[mid])
        {
            return binarySearch(Arr, beg, mid - 1, key);
        }
        else
        {
            return binarySearch(Arr, mid + 1, end, key);
        }
    }

    return -1;
}

int main()
{
    int N, key;
    int found;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d elements of array:\n", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    // Bubble Sort in ascending order
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                int temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }


    printf("Array after sorting in ascending order:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    // Recursive Binary Search

    found = binarySearch(Arr, 0, N - 1, key);

    if (found != -1)
    {
        printf("Element found at position %d\n", found + 1);
    }
    else
    {
        printf("Element not found in array\n");
    }
 
   return 0;

}
