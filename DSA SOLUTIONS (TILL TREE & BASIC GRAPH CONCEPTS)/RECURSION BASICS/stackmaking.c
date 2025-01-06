#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
  int data;
     struct nodes* next;

}node;

node * push( node * head,node **top ,int value){
   
   
  node* newnode=(node *)malloc(sizeof(node));
  newnode->data=value;
  newnode->next=NULL;
  if(head==NULL){
   
   head=newnode;
   *top=newnode;
  }
  else{
    (*top)->next=newnode;
    (*top)=newnode;

  }
  return head;

}
void printqueue( node* head){
  node * temp=head;
  while(temp!=NULL){
    printf(" %d -> ",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");

}

void printstack(node * head){
  node *top=head;
  node *p=NULL;
  while((top->next)!=NULL){

    top=top->next;

  }
   printf("%d ->",top->data);
  do{
    p=head;
    while((p->next)!=top){
    p=p->next;
  }
 
  top=p;
  printf(" %d ->",top->data);

  }
  while(p!=head);
 
  printf("NULL\n");

}

void printstackrecursion(node *head){
  if(head!=NULL){
    printstackrecursion(head->next);
    printf(" %d -> ",head->data);

  }
  return;
}

int main(){
  node *head=NULL;
  node* top=NULL;
  head=push(head,&top,1);
  head=push(head,&top,2);
  head=push(head,&top,3);
  head=push(head,&top,4);
  
 printqueue(head);
 printstack(head);
 printstackrecursion(head);



  return 0;


}