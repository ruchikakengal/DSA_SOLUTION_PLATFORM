#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int v;
    int e;
    int *adjmatrix; // Single pointer for adjacency matrix
} graph;

typedef struct queues
{
    int rare;
    int front;
    int size;
    int *arr;
} queue;

void enqueue(queue *, int);
int dequeue(queue *);
int visited[100] = {0};
graph *create_graph();
void bfs(graph *, queue *, int);
void display(graph *);

int main()
{
    graph *g = NULL;
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rare = -1;
    q->size = 100;
    q->arr = (int *)malloc(sizeof(int) * 100); // Allocate memory for queue array
    g = create_graph();
    display(g);
    bfs(g, q, 0);
    free(q->arr); // Free allocated memory
    free(q);
    free(g->adjmatrix); // Free adjacency matrix memory
    free(g);
    return 0;
}

graph *create_graph()
{
    int u, v;
    graph *g = (graph *)malloc(sizeof(graph));
    if (g != NULL)
    {
        printf("Enter number of vertices: ");
        scanf("%d", &(g->v));
        printf("Enter number of edges: ");
        scanf("%d", &(g->e));
        g->adjmatrix = (int *)malloc(sizeof(int) * g->v * g->v);

        // Initialize the adjacency matrix to 0
        for (int i = 0; i < g->v; i++)
        {
            for (int j = 0; j < g->v; j++)
            {
                g->adjmatrix[i * g->v + j] = 0; // Using single pointer indexing
            }
        }
        printf("Enter pair of source node and destination node:\n");
        for (int i = 0; i < g->e; i++)
        {
            scanf("%d %d", &u, &v);
            g->adjmatrix[u * g->v + v] = 1; // Set edge
            g->adjmatrix[v * g->v + u] = 1; // Set reverse edge for undirected graph
        }
    }
    return g;
}

void display(graph *g)
{
    if (g == NULL)
    {
        return;
    }
    for (int i = 0; i < g->v; i++)
    {
        printf("For vertex %d:\n", i);
        for (int j = 0; j < g->v; j++)
        {
            if (g->adjmatrix[i * g->v + j] == 1)
            {
                printf("%d -> %d\n", i, j);
            }
        }
        printf("\n");
    }
}

void enqueue(queue *q, int num)
{
    if (q->rare == q->size - 1)
    {
        printf("Queue is full...\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rare++;
    q->arr[q->rare] = num;
}

int dequeue(queue *q)
{
    if (q->front == -1 || q->front > q->rare)
    {
        return -1;
    }
    int a = q->arr[q->front];
    q->front++;
    return a;
}

void bfs(graph *g, queue *q, int i)
{
    printf("Starting from 0:\n");
    visited[i] = 1;
    enqueue(q, i);
    while (q->front <= q->rare)
    {
        int node = dequeue(q);
        printf("Node visited: %d\n", node);
        for (int j = 0; j < g->v; j++)
        {
            if (g->adjmatrix[node * g->v + j] == 1 && !visited[j])
            {
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}
