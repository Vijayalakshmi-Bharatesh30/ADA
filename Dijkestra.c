#include <stdio.h>
#define INF 9999

int main() {
    int n, i, j, src, u, v, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int g[n][n], d[n], vis[n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++) {
        d[i] = INF;
        vis[i] = 0;
    }

    d[src] = 0;

    for(i = 0; i < n - 1; i++) {

        min = INF;

        for(j = 0; j < n; j++)
            if(!vis[j] && d[j] < min)
                min = d[j], u = j;

        vis[u] = 1;

        for(v = 0; v < n; v++)
            if(g[u][v] && !vis[v] && d[u] + g[u][v] < d[v])
                d[v] = d[u] + g[u][v];
    }

    printf("\nShortest distances:\n");

    for(i = 0; i < n; i++)
        printf("%d -> %d\n", i, d[i]);

    return 0;
}
