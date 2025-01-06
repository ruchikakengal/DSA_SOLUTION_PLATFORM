#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count the number of leaf nodes
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // If the tree is empty, return 0
    }

    // If the node is a leaf (no left or right child), return 1
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // Otherwise, count the leaf nodes in both subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count the number of nodes with one child
int countOneChildNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // If the tree is empty, return 0
    }

    // Count the current node if it has exactly one child (left or right)
    int count = 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        count = 1; // Node has exactly one child
    }

    // Recursively count for left and right subtrees
    return count + countOneChildNodes(root->left) + countOneChildNodes(root->right);
}

// Function to count the number of nodes with two children
int countTwoChildNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // If the tree is empty, return 0
    }

    // Count the current node if it has exactly two children (both left and right)
    int count = 0;
    if (root->left != NULL && root->right != NULL)
    {
        count = 1; // Node has two children
    }

    // Recursively count for left and right subtrees
    return count + countTwoChildNodes(root->left) + countTwoChildNodes(root->right);
}

// Function to count the total number of nodes
int countTotalNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // If the tree is empty, return 0
    }

    // Count the current node and recursively count for left and right subtrees
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

// Main function
int main()
{
    struct Node *root = NULL;
    int n, i, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    int leafCount = countLeafNodes(root);
    int oneChildCount = countOneChildNodes(root);
    int twoChildCount = countTwoChildNodes(root);
    int totalNodeCount = countTotalNodes(root);

    printf("The number of leaf nodes: %d\n", leafCount);
    printf("The number of nodes with one child: %d\n", oneChildCount);
    printf("The number of nodes with two children: %d\n", twoChildCount);
    printf("The total number of nodes: %d\n", totalNodeCount);

    return 0;
}
