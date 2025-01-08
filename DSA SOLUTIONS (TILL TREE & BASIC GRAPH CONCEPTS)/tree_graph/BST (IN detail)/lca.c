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
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the LCA of two nodes in the BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    // If root is NULL, return NULL (base case)
    if (root == NULL) {
        return NULL;
    }

    // If both n1 and n2 are smaller than root, then LCA lies in the left subtree
    if (n1 < root->data && n2 < root->data) {
         return findLCA(root->left, n1, n2);
    }

    // If both n1 and n2 are greater than root, then LCA lies in the right subtree
    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    // If one key is smaller and the other is larger, root is the LCA
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, i, value, n1, n2;

    // Input number of nodes
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Input values for nodes and insert them into the BST
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input the two nodes whose LCA is to be found
    printf("Enter the two nodes to find their LCA: ");
    scanf("%d %d", &n1, &n2);

    // Find the LCA
    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        printf("The LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("One or both nodes are not present in the tree.\n");
    }

    return 0;
}
