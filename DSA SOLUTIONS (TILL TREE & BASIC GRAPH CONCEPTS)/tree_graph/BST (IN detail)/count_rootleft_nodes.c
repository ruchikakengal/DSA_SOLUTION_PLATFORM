#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
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

// Function to count nodes in a given subtree
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count nodes on the left-hand side of the root
int countLeftNodes(Node* root) {
    if (root == NULL || root->left == NULL) {
        return 0;
    }
    return countNodes(root->left);
}

// In-order traversal to display the BST
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    Node* root = NULL;

    // Example tree creation
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("In-order Traversal of the BST:\n");
    inOrder(root);
    printf("\n");

    // Count nodes on the left-hand side of the root
    int leftNodeCount = countLeftNodes(root);
    printf("Total number of nodes on the left-hand side of the root: %d\n", leftNodeCount);

    return 0;
}
