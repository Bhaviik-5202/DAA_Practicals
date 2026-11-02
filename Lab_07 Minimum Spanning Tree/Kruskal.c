/*
Lab 07 - Cat A: Kruskal's Minimum Spanning Tree Algorithm
Time Complexity: O(E log E) or O(E log V)
Space Complexity: O(V + E)
*/
#include <stdio.h>
#include <time.h>

struct Edge {
    int src, dest, weight;
};

int findParent(int parent[], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void kruskal(int V, int E, struct Edge edges[]) {
    // Sort edges by weight using simple bubble sort
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalWeight = 0;
    int count = 0;

    printf("\nEdges in Minimum Spanning Tree (Kruskal):\n");
    printf("Edge \tWeight\n");

    for (int i = 0; i < E && count < V - 1; i++) {
        int root1 = findParent(parent, edges[i].src);
        int root2 = findParent(parent, edges[i].dest);

        if (root1 != root2) {
            printf("%d -- %d \t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            totalWeight += edges[i].weight;
            parent[root1] = root2;
            count++;
        }
    }

    printf("Total Minimum Weight = %d\n", totalWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    clock_t start = clock();
    kruskal(V, E, edges);
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time = %f Seconds\n", cpu_time);

    return 0;
}
