#include <stdio.h>

struct Result
{
    int max;
    int min;
};

struct Result findMaxMin(int Arr[], int low, int high)
{
    struct Result result, left, right;

    if (low == high)
    {
        result.max = result.min = Arr[low];
        return result;
    }

    if (high == low + 1)
    {
        if (Arr[low] > Arr[high])
        {
            result.max = Arr[low];
            result.min = Arr[high];
        }
        else
        {
            result.max = Arr[high];
            result.min = Arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMaxMin(Arr, low, mid);
    right = findMaxMin(Arr, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main()
{
    int n, Arr[100];
    struct Result result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &Arr[i]);

    result = findMaxMin(Arr, 0, n - 1);

    printf("Maximum element: %d\n", result.max);
    printf("Minimum element: %d\n", result.min);

    return 0;
}
