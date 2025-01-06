#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive insertion in BST
struct node* insertRecursive(struct node* root, int key) {
    if (root == NULL) {
        // If tree is empty, create the root node
        return createNode(key);
    }

    if (key < root->data) {
        // Insert into the left subtree
        root->left = insertRecursive(root->left, key);
    } 
    else if (key > root->data) {
        // Insert into the right subtree
        root->right = insertRecursive(root->right, key);
    }
    else{
        printf("no 2 nodes can have same value in bst");
    }
    // Return the unchanged root pointer
    return root;
}

// Non-recursive insertion in BST
void insertNonRecursive(struct node* root, int key) {
    struct node* prev = NULL;

    // Traverse the BST to find the correct position
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot insert, key already exists.\n");
            return;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
//one condition left here ie when root==null so refer another code for insertion via non recursive nature

    // Create a new node for the key
    struct node* newNode = createNode(key);

    // Attach the new node to the parent
    if (key < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

// Inorder traversal to display the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;

    // Recursive Insertion
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);

    printf("Inorder traversal after recursive insertion:\n");
    inorderTraversal(root);
    printf("\n");

    // Non-recursive Insertion
    insertNonRecursive(root, 25);
    insertNonRecursive(root, 35);

    printf("Inorder traversal after non-recursive insertion:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
