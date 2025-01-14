#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

// Function to create a graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Function to print the distances
void printDistances(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Function to implement Bellman-Ford Algorithm
void bellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Initialize distances from source to all vertices as infinite
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dest;
        int weight = graph->edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    printDistances(dist, V);
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    Graph* graph = createGraph(V, E);

    // Adding edges
    graph->edges[0] = (Edge){0, 1, -1};
    graph->edges[1] = (Edge){0, 2, 4};
    graph->edges[2] = (Edge){1, 2, 3};
    graph->edges[3] = (Edge){1, 3, 2};
    graph->edges[4] = (Edge){1, 4, 2};
    graph->edges[5] = (Edge){3, 2, 5};
    graph->edges[6] = (Edge){3, 1, 1};
    graph->edges[7] = (Edge){4, 3, -3};

    bellmanFord(graph, 0);

    free(graph->edges);
    free(graph);

    return 0;
}
