#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n, capacity;
    struct Item items[100];
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit +=
                items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit: %.2f\n", totalProfit);

    return 0;
}

