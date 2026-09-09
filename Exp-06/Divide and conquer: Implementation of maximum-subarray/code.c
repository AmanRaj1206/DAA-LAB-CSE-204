#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxCrossingSum(int Arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = -999999;
    int rightSum = -999999;

    for (int i = mid; i >= low; i--)
    {
        sum += Arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += Arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArray(int Arr[], int low, int high)
{
    if (low == high)
        return Arr[low];

    int mid = (low + high) / 2;

    int left = maxSubArray(Arr, low, mid);
    int right = maxSubArray(Arr, mid + 1, high);
    int cross = maxCrossingSum(Arr, low, mid, high);

    return max(max(left, right), cross);
}

int main()
{
    int n, Arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &Arr[i]);

    printf("Maximum subarray sum: %d\n",
           maxSubArray(Arr, 0, n - 1));

    return 0;
}
