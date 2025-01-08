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

// Function to print all nodes greater than a given value
void printGreaterThan(struct Node* root, int value) {
    if (root == NULL) {
        return; // Base case: If the tree is empty, do nothing
    }

    if (root->data > value) {
        // Print the current node, then explore both subtrees
       
        printGreaterThan(root->left, value);
         printf("%d ", root->data);
        printGreaterThan(root->right, value);
    } else {
        // Skip the current node and move to the right subtree
        printGreaterThan(root->right, value);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, i, value, threshold;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the threshold value: ");
    scanf("%d", &threshold);

    printf("Nodes greater than %d are: ", threshold);
    printGreaterThan(root, threshold);
    printf("\n");

    return 0;
}
