#include <stdio.h>

#define MAX 10

struct Edge
{
    int u, v, weight;
};

int parent[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unionSet(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

void kruskal(int graph[MAX][MAX], int n)
{
    struct Edge edges[MAX * MAX];
    int edgeCount = 0;
    int edgeUsed = 0;
    int minCost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    /* Convert adjacency matrix to edge list */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    /* Sort edges by weight */
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = i + 1; j < edgeCount; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("Kruskal's Algorithm:\n");
    printf("Edges in MST:\n");

    for (int i = 0; i < edgeCount && edgeUsed < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            unionSet(u, v);

            printf("%d - %d : %d\n",
                   u, v, edges[i].weight);

            minCost += edges[i].weight;
            edgeUsed++;
        }
    }

    if (edgeUsed == n - 1)
        printf("Minimum Cost: %d\n", minCost);
    else
        printf("MST does not exist because the graph is disconnected.\n");
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

    kruskal(graph, 6);

    return 0;
}
