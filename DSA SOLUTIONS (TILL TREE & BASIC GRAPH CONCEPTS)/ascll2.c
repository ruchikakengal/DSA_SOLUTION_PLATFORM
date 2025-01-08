#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;


}node;
void createnode(node **head ){
    int data;

    node* newnode= (node*)malloc(sizeof(node));
    printf("enter value");
    printf("\n");
    scanf("%d",&data);
    printf("\n");

    newnode-> data= data;
    newnode-> next=NULL;

    if(*head==NULL){

        *head=newnode;

    }
    else{
        newnode-> next = *head;
        *head=newnode;
    }
}

void ascll(node ** head){

if(*head==NULL){
   printf("empty ll");
   printf("\n");
}
else{
node * p= *head;
node *q= p->next;
int temp=0;
    while((p->next)!=NULL){
         q=p->next;
    while(q!=NULL){

   if((p->data )> (q->data)){
         temp=p->data;
        p->data=q->data;
        q->data=temp;
        }

        q=q->next ;

    }
    p=p->next;
    }}
}


void printll(node *head){
    if(head==NULL){
        printf("empty ");
        printf("\n");
       

    }
    else{

    while(head!=NULL){
        printf("%d",head->data);
        printf("\n");
        head=head->next;
    }
    }
}
int main(){
    int num=1;
     node *head=NULL;

     while(num){

    createnode(&head);
    printf("want to insert more?type 1 else 0" );
    scanf("%d",&num);

     }

ascll(&head);

printll(head);
return 0;

}