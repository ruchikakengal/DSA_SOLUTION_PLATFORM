#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in a given subtree
struct node* findMin(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;  // Go to the leftmost node
    }
    return root;
}

// Function to delete a node in a BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;  // Tree is empty
    }

    // If the key to be deleted is smaller than root's data, it is in the left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than root's data, it is in the right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If the key is the same as the root's data, this is the node to be deleted
    else {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);  // Free the node and return NULL
            root = NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;  // Promote the right child
            free(temp);
        }
        else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;  // Promote the left child
            free(temp);
        }
        // Case 3: Node has two children
        else {
            // Find the in-order successor (smallest in the right subtree)
            struct node* temp = findMin(root->right);
            
            // Copy the in-order successor's content to this node
            root->data = temp->data;
            
            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Function to perform inorder traversal (for testing)
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Creating a simple BST
    struct node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 20);  // Node with no children
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);  // Node with one child
    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);  // Node with two children
    printf("Inorder traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
