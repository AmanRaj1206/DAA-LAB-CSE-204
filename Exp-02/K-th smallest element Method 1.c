#include <stdio.h>

int main()
{
    int N, K;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d elements of array:\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &K);

    if (K < 1 || K > N)
    {
        printf("Invalid value of K\n");
        return 0;
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

    printf("Array after sorting:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\n%dth smallest element = %d\n", K, Arr[K - 1]);

    return 0;
}
