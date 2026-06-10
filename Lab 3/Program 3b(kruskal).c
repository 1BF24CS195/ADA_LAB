#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

void union_set(int i, int j)
{
    parent[j] = i;
}

void kruskal(int cost[10][10], int n)
{
    int i, j, min, a, b, u, v;
    int ne = 1, mincost = 0;

    while(ne < n)
    {
        min = 999;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v)
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
            union_set(u, v);
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum cost = %d\n", mincost);
}

int main()
{
    int n, cost[10][10];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    kruskal(cost, n);

    return 0;
}
