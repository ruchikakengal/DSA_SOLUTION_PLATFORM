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

// Function to calculate the sum of all nodes in the BST
int sumOfNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // Base case: If the tree is empty, return 0
    }
    // Recursive case: Sum of current node + sum of left subtree + sum of right subtree
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
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

    int totalSum = sumOfNodes(root);
    printf("The sum of all nodes in the BST is: %d\n", totalSum);

    return 0;
}
