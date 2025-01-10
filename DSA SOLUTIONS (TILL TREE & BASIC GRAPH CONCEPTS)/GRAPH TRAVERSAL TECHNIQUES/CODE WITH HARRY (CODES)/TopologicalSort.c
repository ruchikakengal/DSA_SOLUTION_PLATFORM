#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// A structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct Node* newAdjListNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of array is V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to perform Topological Sort using Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* inDegree = (int*)calloc(V, sizeof(int));

    // Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->array[i].head;
        while (temp) {
            inDegree[temp->dest]++;
            temp = temp->next;
        }
    }

    // Create a queue to store vertices with in-degree 0
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    // Add all vertices with in-degree 0 to the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }

    // Perform topological sort
    int count = 0;
    int* topoOrder = (int*)malloc(V * sizeof(int));

    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        // Reduce in-degree of adjacent vertices
        struct Node* temp = graph->array[u].head;
        while (temp) {
            if (--inDegree[temp->dest] == 0)
                queue[rear++] = temp->dest;
            temp = temp->next;
        }
    }

    // Check for a cycle
    if (count != V) {
        printf("The graph contains a cycle. Topological sort is not possible.\n");
        return;
    }

    // Print topological order
    printf("Topological Sort: ");
    for (int i = 0; i < count; i++)
        printf("%d ", topoOrder[i]);
    printf("\n");

    free(queue);
    free(topoOrder);
    free(inDegree);
}

// Driver program to test the above functions
int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Graph Topological Sort using Kahn's Algorithm:\n");
    topologicalSort(graph);

    return 0;
}
