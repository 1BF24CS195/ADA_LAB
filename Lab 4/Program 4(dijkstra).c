#include<stdio.h>

#define MAX 100
#define INF 9999

int cost[MAX][MAX], dist[MAX], visited[MAX], n;

void dijkstra(int start) {
    int i, j, min, u;

    for(i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(i = 1; i < n; i++) {
        min = INF;

        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && (min + cost[u][j] < dist[j])) {
                dist[j] = min + cost[u][j];
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("\nShortest distances from vertex %d:\n", start);
    for(i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}


