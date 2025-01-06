#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
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

// Recursive function to find the maximum value in a BST
int findMaxRecursive(Node* root) {
    if (root == NULL) {
        return -1;  // Sentinel value for an empty tree
    }

    // Recur on the right subtree to find the max value
    if (root->right != NULL) {
        return findMaxRecursive(root->right);
    }

    // If there's no right child, root is the maximum node
    return root->data;
}

// In-order traversal to print the BST
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int nodes[] = {20, 10, 30, 5, 15, 25, 35};
    int size = sizeof(nodes) / sizeof(nodes[0]);

    // Build BST
    for (int i = 0; i < size; i++) {
        root = insert(root, nodes[i]);
    }

    printf("In-order traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    // Find maximum value in BST
    int maxValue = findMaxRecursive(root);
    printf("Maximum value in BST: %d\n", maxValue);

    return 0;
}
