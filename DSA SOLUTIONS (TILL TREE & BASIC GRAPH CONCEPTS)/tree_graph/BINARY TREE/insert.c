#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Tree
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

// Recursive function to insert a node in the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // If the root is NULL, create a new node and return it
    }

    // Recursively insert nodes in left or right subtree
    if (root->left == NULL) {
        root->left = insert(root->left, data);
    } else if (root->right == NULL) {
        root->right = insert(root->right, data);
    } else {
        // This example places nodes in the left subtree if both children are non-null
        root->left = insert(root->left, data);
    }

    return root;
}

// Function for inorder traversal (prints elements in sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Print node data
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Input values for nodes and insert them into the Binary Tree
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Print the tree in-order (for testing purposes)
    printf("In-order traversal of the Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
