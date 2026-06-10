#include <stdio.h>
#define INF 999

int main()
{
    int n, cost[10][10];
    int visited[10] = {0};
    int i, j, min, u, v;
    int edge_count = 0;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while(edge_count < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d  cost = %d\n", u, v, min);

        visited[v] = 1;
        mincost += min;
        edge_count++;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
