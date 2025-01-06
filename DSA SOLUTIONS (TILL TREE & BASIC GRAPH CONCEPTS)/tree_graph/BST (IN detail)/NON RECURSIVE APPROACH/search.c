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

// Non-recursive function to search for a node in the BST
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        // If the key is smaller, move to the left child
        if (key < root->data) {
            root = root->left;
        }
        // If the key is greater, move to the right child
        else if (key > root->data) {
            root = root->right;
        }
        // If the key matches the root's data, return the node
        else {
            return root;
        }
    }
    // Return NULL if the key is not found in the tree
    return NULL;
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, i, value, key;

    // Input number of nodes
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Input values for nodes and insert them into the BST
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input the key to search for
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    // Search for the key in the BST
    struct Node* result = search(root, key);

    if (result != NULL) {
        printf("Node with key %d found in the BST.\n", key);
    } else {
        printf("Node with key %d not found in the BST.\n", key);
    }

    return 0;
}
