/*
Lab 07 - Cat A: Prim's Minimum Spanning Tree Algorithm
Time Complexity: O(V^2)
Space Complexity: O(V)
*/
#include <stdio.h>
#include <limits.h>
#include <time.h>

void prim(int V, int graph[V][V]) {
    int parent[V];
    int key[V];
    int inMST[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break;
        inMST[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    printf("\nEdges in Minimum Spanning Tree (Prim):\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d -- %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Minimum Weight = %d\n", totalWeight);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix (%d x %d, 0 for no edge):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    clock_t start = clock();
    prim(V, graph);
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time = %f Seconds\n", cpu_time);

    return 0;
}
