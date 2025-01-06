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

// Function to find the kth smallest element in the BST using in-order traversal
void inorder(struct Node* root, int* count, int k, int* result) {
    if (root == NULL) {
        return;
    }

    // Traverse left subtree
    inorder(root->left, count, k, result);

    // Increment count when visiting a node
    (*count)++;

    // If count matches k, store the result
    if (*count == k) {
        *result = root->data;
        return;
    }

    // Traverse right subtree
    inorder(root->right, count, k, result);
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, i, value, k, result = -1, count = 0;

    // Input number of nodes
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Input values for nodes and insert them into the BST
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input the value of k
    printf("Enter the value of k (kth smallest element): ");
    scanf("%d", &k);

    // Find the kth smallest element
    inorder(root, &count, k, &result);

    if (result != -1) {
        printf("The %dth smallest element is: %d\n", k, result);
    } else {
        printf("There are fewer than %d nodes in the tree.\n", k);
    }

    return 0;
}
