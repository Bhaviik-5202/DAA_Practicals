/*
Lab 08 - Cat A: Dijkstra's Single Source Shortest Path Algorithm
Time Complexity: O(V^2)
Space Complexity: O(V)
*/
#include <stdio.h>
#include <limits.h>
#include <time.h>

void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1 || dist[u] == INT_MAX) break;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest Distances from Source %d:\n", src);
    printf("Vertex \tDistance\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \tINF\n", i);
        } else {
            printf("%d \t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix (%d x %d, 0 for no edge):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    clock_t start = clock();
    dijkstra(V, graph, src);
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time = %f Seconds\n", cpu_time);

    return 0;
}
