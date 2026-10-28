#include <stdio.h>

#define N 4
#define INF 99999

void floydWarshall(int graph[N][N])
{
    int dist[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i][i] < 0)
        {
            printf("Negative weight cycle detected.\n");
            return;
        }
    }

    printf("All-Pairs Shortest Distance Matrix:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[N][N] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
