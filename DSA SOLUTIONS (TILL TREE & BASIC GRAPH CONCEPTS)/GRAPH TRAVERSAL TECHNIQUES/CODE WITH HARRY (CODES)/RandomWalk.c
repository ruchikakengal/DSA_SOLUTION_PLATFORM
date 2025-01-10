#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Graph structure
struct Graph {
    int V;
    int** adjMatrix;
};

// Create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Perform a random walk
void randomWalk(struct Graph* graph, int start, int steps) {
    srand(time(NULL));
    int current = start;

    printf("Random Walk Starting from Node %d:\n", start);
    for (int i = 0; i < steps; i++) {
        printf("%d ", current);

        // Find neighbors
        int* neighbors = (int*)malloc(graph->V * sizeof(int));
        int count = 0;

        for (int j = 0; j < graph->V; j++) {
            if (graph->adjMatrix[current][j]) {
                neighbors[count++] = j;
            }
        }

        // If no neighbors, end the walk
        if (count == 0) break;

        // Randomly pick a neighbor
        current = neighbors[rand() % count];
        free(neighbors);
    }
    printf("\n");
}

// Driver code
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    randomWalk(graph, 0, 10); // Perform 10 steps of random walk starting from node 0

    return 0;
}
