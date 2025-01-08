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

// Define Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Define Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize a queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue (add element to the rear)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        q->front = q->rear = newNode;
        return;
    }

    // Otherwise, add the new node at the rear and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue (remove element from the front)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Return a sentinel value
    }

    // Get the front node
    struct Node* temp = q->front;
    int dequeuedValue = temp->data;

    // Move the front pointer to the next node
    q->front = q->front->next;

    // If the front becomes NULL, update the rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); // Free the dequeued node
    return dequeuedValue;
}

// Function to perform BFS traversal
void BFS(int graph[MAX][MAX], int start)
{
    int visited[MAX] = { 0 };  // Array to track visited nodes
    struct Queue q;
    initQueue(&q);

    visited[start] = TRUE;  // Mark the start node as visited
    enqueue(&q, start);     // Enqueue the start node

    printf("BFS: ");

    while (!isEmpty(&q)) {
        int current = dequeue(&q);  // Dequeue the front node
        printf("%d ", current);

        // Visit all the adjacent nodes of the current node
        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = TRUE;  // Mark the adjacent node as visited
                enqueue(&q, i);     // Enqueue the adjacent node
            }
        }
    }

    printf("\n");
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
