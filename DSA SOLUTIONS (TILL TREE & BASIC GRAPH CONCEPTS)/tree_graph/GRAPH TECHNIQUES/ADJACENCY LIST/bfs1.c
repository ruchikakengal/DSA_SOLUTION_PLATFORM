// adjacency list
// bfs using adjacency list
#include <stdio.h>
#include <stdlib.h>
#define maxVertex 5
#define MAX 10
typedef struct nodes
{
    int vNum;
    struct nodes *next;
} node;
typedef struct list
{
    node *head;
} list;
typedef struct queue
{
    int size, rare, front;
    int *arr;
} queue;

int visited[MAX] = {0};
list *adjlist[maxVertex] = {0};
void addNode(int, int);
void display();
void enqueue(queue *, int);
int dequeue(queue *);
void bfs(queue *, int);
int main()
{
    for (int i = 0; i < maxVertex; i++)
    {
        adjlist[i] = (list *)malloc(sizeof(list));
        adjlist[i]->head = NULL;
    }
    addNode(0, 1);
    addNode(0, 2);
    addNode(1, 2);
    addNode(2, 3);
    addNode(3, 4);
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rare = -1;
    q->size = MAX;
    q->arr = (int *)malloc(sizeof(int)*(q->size));
    display();
    printf("bfs.....\n");
    bfs(q, 0);
}
void addNode(int s, int d)
{
    node *dest = NULL, *temp = NULL;
    dest = (node *)malloc(sizeof(node));
    dest->vNum = d;
    dest->next = NULL;
    if (adjlist[s]->head == NULL)
    {
        adjlist[s]->head = dest;
        return;
    }
    else
    {
        temp = adjlist[s]->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = dest;
    }
}
void display()
{
    for (int i = 0; i < maxVertex; i++)
    {
        node *p = NULL;
        p = adjlist[i]->head;
        printf("for vertex %d: ", i);
        while (p != NULL)
        {
            printf("%d -> ", p->vNum);
            p = p->next;
        }
        printf("NULL\n");
    }
}
void enqueue(queue *q, int num)
{
    if (q->rare == q->size - 1)
    {
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
    int a = -1;
    if (q->front == -1 && q->front > q->rare)
    {
        return a;
    }
    a = q->arr[q->front];
    q->front++;
    if (q->front > q->rare) {
        q->front = q->rare = -1; // Reset the queue
    }
    return a;
}
void bfs(queue *q, int i)
{
    printf(" %d ", i);
    visited[i] = 1;
    enqueue(q, i);
    while (q->front != -1 )
    {
        int nod = dequeue(q);
        node *p = adjlist[nod]->head;
        while (p != NULL)
        {
            int x = p->vNum;
            if (!visited[x])
            {
                printf("%d ",p->vNum);
                visited[x] = 1;
                enqueue(q, x);
            }
            p = p->next;
        }
    }
}