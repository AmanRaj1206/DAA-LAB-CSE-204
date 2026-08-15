#include <stdio.h>
#include <math.h>

int main()
{
    double a, r, sum;
    int n;

    printf("Enter the first term (a): ");
    scanf("%lf", &a);

    printf("Enter the common ratio (r): ");
    scanf("%lf", &r);

    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    if (r == 1)
    {
        sum = a * n;
    }
    else
    {
        sum = a * (pow(r, n) - 1) / (r - 1);
    }

    printf("Sum of geometric series = %.2lf\n", sum);

    return 0;
}
