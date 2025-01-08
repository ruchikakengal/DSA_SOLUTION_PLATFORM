#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

// Function prototypes
void insertEdge(int graph[MAX][MAX], int u, int v);
void deleteEdge(int graph[MAX][MAX], int u, int v);
int searchEdge(int graph[MAX][MAX], int u, int v);
void BFS(int graph[MAX][MAX], int start);

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

    // Perform BFS
    printf("BFS starting from node 2:\n");
    BFS(graph, 2);

    return 0;
}

// Function to insert an edge into the graph
void insertEdge(int graph[MAX][MAX], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

// Function to delete an edge from the graph
void deleteEdge(int graph[MAX][MAX], int u, int v)
{
    graph[u][v] = 0;
    graph[v][u] = 0; // For undirected graph
}

// Function to search for an edge in the graph
int searchEdge(int graph[MAX][MAX], int u, int v)
{
    return graph[u][v];
}

// Function to perform BFS traversal
void BFS(int graph[MAX][MAX], int start)
{
    int visited[MAX] = { 0 };  // Array to track visited nodes
    int queue[MAX], front = 0, rear = 0;

    visited[start] = TRUE;  // Mark the start node as visited
    queue[rear++] = start;  // Enqueue the start node

    printf("BFS: ");

    while (front < rear) {
        int current = queue[front++];  // Dequeue the front node
        printf("%d ", current);

        // Visit all the adjacent nodes of the current node
        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = TRUE;  // Mark the adjacent node as visited
                queue[rear++] = i;   // Enqueue the adjacent node
            }
        }
    }

    printf("\n");
}
