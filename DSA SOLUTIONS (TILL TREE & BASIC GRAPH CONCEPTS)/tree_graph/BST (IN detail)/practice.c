#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node * left;
  struct node * right;
};
struct node* createnode(int data){
  struct node * newnode=(struct node*)malloc(sizeof(struct node));

  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;

  return newnode;
}



int counttwochild(struct node * root){

  if(root==NULL){

    return 0;

  }

  int count=0;
  if(root->left !=NULL && root->right !=NULL){
    count =1;

  }

  return count+counttwochild(root->left)+counttwochild(root->right);

}


struct node* insert(struct node* root,int data){

  if(root==NULL){

    return createnode(data);

  }

  if(data<root->data){
    root->left=insert(root->left,data);
  }

  else if (data>root->data){

    root->right=insert(root->right,data);

  }
   else{
    printf("no 2 node can have same values");

   }
  return root;
}

int count(struct node* root){

  if(root==NULL)
  return 0;
  else{

    

    return count(root->left)+ 1 + count(root->right);

  }
}

void inorder(struct node* root){

  if(root!=NULL){

    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);

  }
}
int main(){


  struct node* root=NULL;
  int n,i,value;
  int c=0;

  printf("enter no of nodes for bst");
  scanf("%d", &n);

  for(i=0;i<n;i++){

    printf("enter value for node");
    scanf("%d",&value);
    root=insert(root,value);
  }

  printf("inorder traversal is \n");

  inorder(root);
  c=count(root);
  printf("count is %d  ", c );

  c=counttwochild(root);
 printf("count is %d", c );

  return 0;


}