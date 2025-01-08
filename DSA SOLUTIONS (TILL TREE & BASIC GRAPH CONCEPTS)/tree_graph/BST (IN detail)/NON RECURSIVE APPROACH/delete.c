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



// Non-recursive function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int key) {
    struct Node *parent = NULL, *curr = root;

    // Traverse to find the node to be deleted and its parent
    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // If the node is not found
    if (curr == NULL) {
        printf("Key not found!\n");
        return root;
    }

    // Case 1: Node is a leaf
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == NULL) {
            // Tree only has one node (root)
            free(curr);
            return NULL;
        } else {
            if (parent->left == curr) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
    }

    // Case 2: Node has one child
    else if (curr->left == NULL || curr->right == NULL) {
        struct Node* child = (curr->left != NULL) ? curr->left : curr->right;
        if (parent == NULL) {
            // Root node with one child
            root = child;
        } else {
            if (parent->left == curr) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        free(curr);
    }

    // Case 3: Node has two children
    else {
        // Find the inorder successor (smallest node in the right subtree)
        struct Node* successorParent = curr;
        struct Node* successor = curr->right;

        // Find the leftmost node in the right subtree (inorder successor)
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current node's data with the inorder successor's data
        curr->data = successor->data;

        // Delete the inorder successor
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        free(successor);
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
