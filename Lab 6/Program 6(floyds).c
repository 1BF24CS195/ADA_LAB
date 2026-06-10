#include <stdio.h>
#define INF 99999

void readMatrix(int cost[10][10], int n)
{
    int i, j;
    printf("Enter the cost matrix(99999 for INF):\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
}

void floyd(int cost[10][10], int n)
{
    int i, j, k;

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
}

void printMatrix(int cost[10][10], int n)
{
    int i, j;

    printf("\nShortest path matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readMatrix(cost, n);
    floyd(cost, n);
    printMatrix(cost, n);

    return 0;
}
