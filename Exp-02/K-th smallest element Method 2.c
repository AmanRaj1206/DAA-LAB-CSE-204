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

    // Selection without fully sorting the array
    for (int i = 0; i < K; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < N; j++)
        {
            if (Arr[j] < Arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Move the minimum element to position i
        int temp = Arr[i];
        Arr[i] = Arr[minIndex];
        Arr[minIndex] = temp;
    }

    printf("%dth smallest element = %d\n", K, Arr[K - 1]);

    return 0;
}
