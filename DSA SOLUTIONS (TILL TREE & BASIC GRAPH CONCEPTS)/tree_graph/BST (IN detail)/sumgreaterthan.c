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

// Function to calculate the sum of all nodes greater than a given value
int sumGreaterThan(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Base case: If the tree is empty, return 0
    }

    if (root->data > value) {
       //printf("Adding %d to the sum.\n", root->data);
        // Include the current node's value and check both subtrees
        return  root->data + sumGreaterThan(root->left, value) + sumGreaterThan(root->right, value);
    } else {
        // Exclude the current node and only check the right subtree (as all left nodes will be <= value)
        //printf("Skipping %d (<= %d).\n", root->data, value);
       return  sumGreaterThan(root->right, value);
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

    int totalSum = sumGreaterThan(root, threshold);
    printf("The sum of all nodes greater than %d is: %d\n", threshold, totalSum);

    return 0;
}
