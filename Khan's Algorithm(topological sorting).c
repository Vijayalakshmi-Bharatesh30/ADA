#include <stdio.h>

#define MAX 20

int main() {
    int n, i, j;
    int adj[MAX][MAX];
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int order[MAX], count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while(front <= rear) {
        int u = queue[front++];
        order[count++] = u;

        for(j = 0; j < n; j++) {
            if(adj[u][j] == 1) {
                in_degree[j]--;
                if(in_degree[j] == 0) {
                    queue[++rear] = j;
                }
            }
        }
    }

    if(count != n) {
        printf("Graph has a cycle - no topological order\n");
    } else {
        printf("Topological Order:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", order[i]);
        }
    }

    return 0;
}
