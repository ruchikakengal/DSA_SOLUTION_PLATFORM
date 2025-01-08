#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
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

// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL; // If the tree is empty, return NULL
    }
    while (root->left != NULL) {
        root = root->left; // Keep going left to find the minimum
    }
    return root;
}

// Function to find the maximum value node in the BST
struct Node* findMax(struct Node* root) {
    if (root == NULL) {
        return NULL; // If the tree is empty, return NULL
    }
    while (root->right != NULL) {
        root = root->right; // Keep going right to find the maximum
    }
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, i, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);

    if (minNode != NULL) {
        printf("The minimum value node is: %d\n", minNode->data);
    } else {
        printf("The tree is empty.\n");
    }

    if (maxNode != NULL) {
        printf("The maximum value node is: %d\n", maxNode->data);
    } else {
        printf("The tree is empty.\n");
    }

    return 0;
}
