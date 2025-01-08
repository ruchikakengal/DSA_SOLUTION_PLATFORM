#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a binary tree is a BST
int isBST(struct Node* root) {
    static struct Node* prev = NULL; // Static variable to keep track of the previous node in inorder traversal

    if (root != NULL) {
        // Check the left subtree
        if (!isBST(root->left)) {
            return 0;
        }
        
        // Check the current node
        if (prev != NULL && root->data <= prev->data) {
            return 0; // BST property violated
        }
        prev = root; // Update previous node

        // Check the right subtree
        if(isBST(root->right)){
            return 1;
        }
    }

    // If root is NULL, it is a valid BST up to this point
    return 1;
}

// Function to insert a node into a BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    // Check if the binary tree is a BST
    if (isBST(root)) {
        printf("The binary tree is a BST.\n");
    } else {
        printf("The binary tree is not a BST.\n");
    }

    return 0;
}
