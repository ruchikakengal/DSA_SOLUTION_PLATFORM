#include<stdio.h>
#include<malloc.h>

struct node{
  int data;
  struct node* left;
  struct node* right;

};

struct node* createnode(int data){
struct node* n;
n=(struct node*)malloc(sizeof(struct node));
n-> data=data;
n->left=NULL;
n->right=NULL;
return n;

}
void * preorder(struct node* root){
  if(root!=NULL){
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);

  }

}


void * postorder(struct node* root){
  if(root!=NULL){
    
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
  }

}

void  inorder(struct node* root){
  if(root==NULL){
    return;
  }
  else{
    
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    
  }

}

int isbst(struct node* root){
  static struct node *prev=NULL;
  
  
    
    if(root!=NULL){
      if(!isbst(root->left)){
        return 0;

      }
    

    if (prev!=NULL && root->data<=prev->data)
    return 0;

    prev=root;
    return isbst(root->right);

    }
    
  

  else{
    return 1;
  }

}
struct node * search(struct node * root,int key){
  if(root==NULL){
    return NULL;
  }
  if(key==root->data){
    return root;

  }
  else if(key<root->data){
     return search(root->left,key);
// we have use return here to maintain efficiency of the code..if we dont use return search and simply write search then also ans will remain same.
  }
  else{
     return search(root->right,key);
  }
}


int main(){


struct node*p=createnode(4);
struct node*p1=createnode(3);
struct node*p2=createnode(5);
struct node*p3=createnode(2);

p->left=p1;
p->right=p2;
p1->left=p3;

preorder(p);
printf("\n");

postorder(p);
printf("\n");

inorder(p);
printf("\n");

printf("%d  ",isbst(p));

struct node * n =search(p,0);
if(n!=NULL){
printf(" ya found %d",n->data);
}
else{
  printf("element not found"); 
}


return 0;


}