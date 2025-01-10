#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }

    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(int** graph, int V, int src) {
    int* dist = (int*)malloc(V * sizeof(int));
    int* visited = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) printf("%d\t%d\n", i, dist[i]);

    free(dist);
    free(visited);
}

// Driver code
int main() {
    int V = 5;
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    // Graph adjacency matrix
    int adjMatrix[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0},
    };

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = adjMatrix[i][j];

    dijkstra(graph, V, 0);

    return 0;
}
