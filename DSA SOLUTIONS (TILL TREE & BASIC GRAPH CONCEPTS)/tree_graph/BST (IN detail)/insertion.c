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
        // If tree is empty or we reach a NULL position, create a new node
        return createNode(data);
    }

    if (data < root->data) {
        // Recursively insert in the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // Recursively insert in the right subtree
        root->right = insert(root->right, data);
    }

    // Return unchanged root
    return root;
}

// Function for inorder traversal (prints elements in sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
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

    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
