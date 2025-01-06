// adjacency list
#include<stdio.h>
#include<stdlib.h>
#define maxVertex 5
typedef struct node
{
    int vNum;
    struct node *next;
}node;
typedef struct list
{
    node *head;
}list;
int visited[100]={0};
list* adjlist[maxVertex]={NULL};
void addNode(int ,int );
void display();
void dfs(int);
int main()
{
    for(int i=0;i<maxVertex;i++)
    {
        adjlist[i]=(list*)malloc(sizeof(list));
        adjlist[i]->head=NULL;
    }
    addNode(0, 1);
    addNode(0, 2);
    addNode(1, 2);
    addNode(2, 3);
    addNode(3, 4);
    display();
    printf("dfs.....\n");
    dfs(0);
}
void addNode(int s,int d)
{
    node *dest=NULL,*temp=NULL;
    dest=(node*)malloc(sizeof(node));
    dest->vNum=d;
    dest->next=NULL;
    if(adjlist[s]->head==NULL)
    {
        adjlist[s]->head=dest;
        return;
    }
    else
    {
        temp=adjlist[s]->head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=dest;
    }
}
void display()
{
    for(int i=0;i<maxVertex;i++)
    {
        node *p=NULL;;
        p=adjlist[i]->head;
        printf("for vertex %d...\n",i);
        while(p!=NULL)
        {
            printf("%d -> %d\n",i,p->vNum);
            p=p->next;
        }
        printf("\n");
    }
}
void dfs(int i)
{
    printf(" %d ",i);
    visited[i]=1;
    node *p=adjlist[i]->head;
    while(p!=NULL)
    {
        int x =p->vNum;
        if(!visited[x])
        {
            dfs(x);
        }
        p=p->next;
    }
}