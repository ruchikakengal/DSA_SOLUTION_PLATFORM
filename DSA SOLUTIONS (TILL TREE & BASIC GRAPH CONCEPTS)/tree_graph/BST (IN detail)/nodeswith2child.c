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

// Function to count nodes having common parents
int countCommonParents(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    // If both left and right children exist, this node is a common parent
    if (root->left != NULL && root->right != NULL) {
        count = 1;
    }

    // Recursively count in left and right subtrees
    return count + countCommonParents(root->left) + countCommonParents(root->right);
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
    int nodes[] = {20, 10, 30, 5, 15, 25, 35, 12};
    int size = sizeof(nodes) / sizeof(nodes[0]);

    // Build BST
    for (int i = 0; i < size; i++) {
        root = insert(root, nodes[i]);
    }

    printf("In-order traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    // Count total nodes having common parents
    int commonParentCount = countCommonParents(root);
    printf("Total nodes having common parents: %d\n", commonParentCount);

    return 0;
}
