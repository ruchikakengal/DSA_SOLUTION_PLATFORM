#include<stdio.h>
#include<stdlib.h>

#define maxvertex 5
#define max 10

typedef struct nodes{
  int vnum;
  struct nodes* next;

}node;

typedef  struct list{

  node *head;

}list;

typedef struct queue{
  int size,r,f;
  int *arr;

}queue;

int visited[max]= {0};
int updvisited[max]= {0};

list *adjlist[maxvertex]={0};


void addnode(int,int);
void display();
void enqueue(queue* ,int);
int dequeue(queue*);
void bfs(queue*,int);

int main(){

  for(int i=0;i<maxvertex;i++){

    adjlist[i]=(list* )malloc(sizeof(list));
    adjlist[i]->head=NULL;

  }

  addnode(0,1);
   addnode(0,3);
    addnode(1,2);
     addnode(2,3);
      addnode(2,4);
  display();


 queue * q=(queue*)malloc(sizeof(queue));

 q->f=-1;
 q->r=-1;
 q->size=max;
 q->arr=(int*)malloc(sizeof(int)*q->size);


printf("bfs traversal is ");
bfs(q,0);

printf("dfs travelal is ");
dfs(0);


return 0;

}

void addnode(int s,int d){

  node* dest=NULL;
  node* temp =NULL;

  dest=(node *)malloc(sizeof(node));dest->vnum=d;
  dest->next=NULL;

  if(adjlist[s]->head==NULL){
    adjlist[s]->head=dest;
    return;

  }
  else{

    temp=adjlist[s]->head;
    while(temp->next!=NULL){
      temp=temp->next;

    }
    temp->next=dest;

  }
}

void display(){

  for(int i=0;i<maxvertex;i++){
    node * p=NULL;
    p=adjlist[i]->head;
    printf("for vertex %d ",i);
    while(p!=NULL){
   
     printf(" %d ->",p->vnum);
     p=p->next;

    }
    printf("NULL\n");



  }
}

void enqueue( queue *q,int num){

  if(q->r==q->size-1){

    return;

  }

  if(q->f==-1){
    q->f=0;

  }

  q->r++;
  q->arr[q->r]=num;

}
int dequeue(queue*q){

int a=-1;
if((q->f==-1) || (q->f >q->r))
{
  return a;
}

a=q->arr[q->f];

q->f++;
if(q->f > q-> r){
  q->r=q->f=-1;
}

return a;


}
void bfs(queue*q,int i){

printf(" %d ",i);
visited[i]=1;
enqueue(q,i);

while(q->f !=-1){

  int nod=dequeue(q);
  node *p=adjlist[nod]->head;
  while(p!=NULL){

    int x=p->vnum;
    if(!visited[x]){
     printf(" %d ",x);
     visited[x]=1;
     enqueue(q,x);


    }
    p=p->next;


  }
}
}
void dfs(int i){
  printf(" %d ",i);
  updvisited[i]=1;

  node *p=adjlist[i]->head;
  while(p!=NULL){
    i=p->vnum;
    if(!updvisited[i]){

      dfs(i);

    }

    p=p->next;

  }
}