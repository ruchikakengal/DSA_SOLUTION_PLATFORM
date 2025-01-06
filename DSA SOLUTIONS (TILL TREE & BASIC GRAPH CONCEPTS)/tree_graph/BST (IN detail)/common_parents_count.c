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

// Function to count the total number of nodes having a common parent
int countNodesWithCommonParent(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    // Check if the current node has both left and right children
    if (root->left != NULL && root->right != NULL) {
        count+=2;
    }

    
    return count +countNodesWithCommonParent(root->right) + countNodesWithCommonParent(root->left) ;
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

    // Count nodes with common parents
    int commonParentCount = countNodesWithCommonParent(root);
    printf("Total number of nodes having a common parent: %d\n", commonParentCount);

    return 0;
}
