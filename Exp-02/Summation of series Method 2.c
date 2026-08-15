#include <stdio.h>

int main()
{
    double a, r, sum = 0;
    int n;

    printf("Enter the first term (a): ");
    scanf("%lf", &a);

    printf("Enter the common ratio (r): ");
    scanf("%lf", &r);

    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    printf("Sum of geometric series = %.2lf\n", sum);

    return 0;
}
