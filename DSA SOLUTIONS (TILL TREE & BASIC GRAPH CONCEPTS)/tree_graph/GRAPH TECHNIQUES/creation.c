#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

// Function prototypes
void insertEdge(int graph[MAX][MAX], int u, int v);
void deleteEdge(int graph[MAX][MAX], int u, int v);
int searchEdge(int graph[MAX][MAX], int u, int v);

int main()
{
    // Initialize adjacency matrix to 0
    int graph[MAX][MAX] = { 0 };

    // Add edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);

    // Search for an edge
    printf("Searching for edge between node 0 and node 1: ");
    if (searchEdge(graph, 0, 1)) {
        printf("Edge exists\n");
    } else {
        printf("Edge does not exist\n");
    }

    // Delete an edge
    printf("Deleting edge between node 2 and node 3...\n");
    deleteEdge(graph, 2, 3);

    // Search for the deleted edge
    printf("Searching for edge between node 2 and node 3: ");
    if (searchEdge(graph, 2, 3)) {
        printf("Edge exists\n");
    } else {
        printf("Edge does not exist\n");
    }

    return 0;
}

// Function to insert an edge into the graph
void insertEdge(int graph[MAX][MAX], int u, int v)
{
    // Set the edge from u to v
    graph[u][v] = 1;
    // Set the edge from v to u (undirected graph)
    graph[v][u] = 1;
    printf("Edge inserted between node %d and node %d\n", u, v);
}

// Function to delete an edge from the graph
void deleteEdge(int graph[MAX][MAX], int u, int v)
{
    // Remove the edge from u to v
    graph[u][v] = 0;
    // Remove the edge from v to u (undirected graph)
    graph[v][u] = 0;
    printf("Edge deleted between node %d and node %d\n", u, v);
}

// Function to search for an edge in the graph
int searchEdge(int graph[MAX][MAX], int u, int v)
{
    // Return the existence of edge u-v
    return graph[u][v];
}
