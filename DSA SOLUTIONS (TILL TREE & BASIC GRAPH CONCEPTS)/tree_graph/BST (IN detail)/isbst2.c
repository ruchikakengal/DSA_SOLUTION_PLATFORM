#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isbst(struct node* root, struct node** prev) {
    if (root != NULL) {
        // Check the left subtree
        if (!isbst(root->left, prev)) {
            return 0;
        }

        // Check the current node
        if (*prev != NULL && root->data <= (*prev)->data) {
            return 0;
        }

        // Update prev to the current node
        *prev = root;

        // Check the right subtree
        return isbst(root->right, prev);
    }
    return 1;
}



int main() {
    struct node* p = createnode(4);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(5);
    struct node* p3 = createnode(2);
    struct node* prev = NULL;

    p->left = p1;
    p->right = p2;
    p1->left = p3;

    printf("Preorder Traversal: ");
    preorder(p);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(p);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(p);
    printf("\n");

    if (isbst(p, &prev)) {
        printf("Yes, it's a BST\n");
    } else {
        printf("No, it's not a BST\n");
    }

    return 0;
}
