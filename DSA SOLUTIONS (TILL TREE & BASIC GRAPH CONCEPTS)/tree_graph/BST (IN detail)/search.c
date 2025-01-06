#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to search an element in BST
struct Node *search(struct Node *root, int key)
{
    // Base case: root is null or key is present at the root
    if (root == NULL || root->data == key)
        return root;

    // If key is smaller than root's data, search in the left subtree
    if (key < root->data)
        return search(root->left, key);

    // Otherwise, search in the right subtree
    return search(root->right, key);
}

int main()
{
    // Creating a sample BST
    struct Node *root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    int key = 40;
    struct Node *result = search(root, key);

    if (result != NULL)
        printf("Element %d found in the BST.\n", key);
    else
        printf("Element %d not found in the BST.\n", key);

    return 0;
}
