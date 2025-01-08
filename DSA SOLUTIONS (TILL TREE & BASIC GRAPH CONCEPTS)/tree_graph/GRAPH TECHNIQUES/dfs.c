#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

// Define a node for the stack (Linked List)
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function prototypes
void insertEdge(int graph[MAX][MAX], int u, int v);
void DFS(int graph[MAX][MAX], int start);
void push(struct StackNode** top, int value);
int pop(struct StackNode** top);
int isEmpty(struct StackNode* top);

int main() {
    int graph[MAX][MAX] = { 0 };

    // Add edges
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);

    // Perform DFS
    printf("DFS starting from node 0:\n");
    DFS(graph, 0);

    return 0;
}

// Function to insert an edge into the graph (undirected graph)
void insertEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Since it's undirected
}

// Function to perform DFS traversal iteratively using stack
void DFS(int graph[MAX][MAX], int start) {
    int visited[MAX] = {0};  // Array to keep track of visited nodes
    struct StackNode* stack = NULL;  // Stack (represented by linked list)
    
    // Start DFS by pushing the start node onto the stack
    push(&stack, start);
    visited[start] = TRUE;  // Mark the start node as visited

    while (!isEmpty(stack)) {
        int current = pop(&stack);  // Pop a node from the stack
        printf("%d ", current);  // Process the current node

        // Visit all adjacent nodes of the current node
        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                push(&stack, i);  // Push unvisited adjacent node onto the stack
                visited[i] = TRUE; // Mark the adjacent node as visited
            }
        }
    }
    printf("\n");
}

// Function to push an element onto the stack
void push(struct StackNode** top, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = *top;  // Point to the current top of the stack
    *top = newNode;  // Update the top pointer to the new node
}

// Function to pop an element from the stack
int pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1;  // Stack is empty
    }
    struct StackNode* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;  // Update top to the next element in the stack
    free(temp);  // Free the memory of the popped node
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return (top == NULL);  // Return TRUE if the stack is empty
}
