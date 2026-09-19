#include <stdio.h>

#define MAX 10
#define INF 999999

void prim(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int edgeUsed = 0;
    int minCost = 0;

    selected[0] = 1;

    printf("Prim's Algorithm:\n");
    printf("Edges in MST:\n");

    while (edgeUsed < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            printf("MST does not exist because the graph is disconnected.\n");
            return;
        }

        selected[v] = 1;

        printf("%d - %d : %d\n", u, v, min);

        minCost += min;
        edgeUsed++;
    }

    printf("Minimum Cost: %d\n", minCost);
}

int main()
{
    int graph[MAX][MAX] =
    {
        {0, 4, 3, 0, 0, 0},
        {4, 0, 1, 2, 0, 0},
        {3, 1, 0, 4, 5, 0},
        {0, 2, 4, 0, 2, 3},
        {0, 0, 5, 2, 0, 6},
        {0, 0, 0, 3, 6, 0}
    };

    prim(graph, 6);

    return 0;
}
