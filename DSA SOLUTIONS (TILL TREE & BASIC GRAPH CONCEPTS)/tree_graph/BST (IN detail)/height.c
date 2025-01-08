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

// Function to find the height of the BST
int height(struct Node* root) {
    if (root == NULL) {
        return -1;  // Height of an empty tree is -1
    }
    int leftHeight = height(root->left);  // Height of the left subtree
    int rightHeight = height(root->right); // Height of the right subtree
    
    // The height of the current node is the maximum height of its left and right subtrees plus 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
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

    int treeHeight = height(root);
    printf("The height of the BST is: %d\n", treeHeight);

    return 0;
}
