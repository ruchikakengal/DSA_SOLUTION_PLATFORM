#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 99999  // Infinite value for no connection

// Function prototypes
void insertEdge(int graph[MAX][MAX], int u, int v, int weight);
void displayGraph(int graph[MAX][MAX]);

int main() {
    // Initialize adjacency matrix to INF (no edge) for all pairs
    int graph[MAX][MAX];
    
    // Initialize the graph with no edges
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = INF; // No connection initially
        }
    }

    // Add edges with weights
    insertEdge(graph, 0, 1, 10);
    insertEdge(graph, 0, 2, 5);
    insertEdge(graph, 1, 2, 2);
    insertEdge(graph, 1, 3, 1);
    insertEdge(graph, 2, 3, 9);
    insertEdge(graph, 3, 4, 4);

    // Display the graph
    printf("Weighted Graph (Adjacency Matrix):\n");
    displayGraph(graph);

    return 0;
}

// Function to insert an edge with weight into the graph
void insertEdge(int graph[MAX][MAX], int u, int v, int weight) {
    // Since it's an undirected graph, set both u-v and v-u to the given weight
    graph[u][v] = weight;
    graph[v][u] = weight;
}

// Function to display the graph (adjacency matrix representation)
void displayGraph(int graph[MAX][MAX]) {
    printf("   ");
    for (int i = 0; i < MAX; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < MAX; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < MAX; j++) {
            if (graph[i][j] == INF)
                printf(" INF ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}