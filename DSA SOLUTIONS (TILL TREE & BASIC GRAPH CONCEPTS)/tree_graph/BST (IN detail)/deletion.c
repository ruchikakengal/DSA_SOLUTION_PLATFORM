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

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Key not found!\n");
        return root;
    }

    // Recur to find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Node is a leaf
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: Node has one child (right)
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 2: Node has one child (left)
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Case 3: Node has two children
            struct Node* temp = findMin(root->right); // Find inorder successor
            root->data = temp->data;                 // Replace with successor
            root->right = deleteNode(root->right, temp->data); // Delete successor
        }
    }
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

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display (Inorder Traversal)\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
