#include <stdio.h>

#define MAX 20

void topologicalSort(int adj[][MAX], int n)
{
    int indegree[MAX] = {0};
    int queue[MAX];
    int topo[MAX];
    int front = 0, rear = 0;
    int count = 0;
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    while(front < rear)
    {
        int v = queue[front++];
        topo[count++] = v;

        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if(count != n)
    {
        printf("Topological sort not possible (Cycle exists)\n");
        return;
    }

    printf("Topological Ordering:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", topo[i]);
    }

    printf("\n");
}

int main()
{
    int adj[MAX][MAX];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj, n);

    return 0;
}
