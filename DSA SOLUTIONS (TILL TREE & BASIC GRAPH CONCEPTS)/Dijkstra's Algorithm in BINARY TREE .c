#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a tree node
typedef struct TreeNode {
    int data;
    int weight;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data, int weight) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to find the shortest path to a leaf node
void dijkstraBinaryTree(TreeNode* root, int currentWeight, int* minWeight) {
    if (!root) return;

    currentWeight += root->weight;

    // If it is a leaf node, update the minimum weight if the current path is shorter
    if (!root->left && !root->right) {
        if (currentWeight < *minWeight) {
            *minWeight = currentWeight;
        }
        return;
    }

    // Recur for left and right subtrees
    dijkstraBinaryTree(root->left, currentWeight, minWeight);
    dijkstraBinaryTree(root->right, currentWeight, minWeight);
}

int main() {
    TreeNode* root = createNode(1, 0);
    root->left = createNode(2, 1);
    root->right = createNode(3, 4);
    root->left->left = createNode(4, 2);
    root->left->right = createNode(5, 3);
    root->right->left = createNode(6, 1);

    int minWeight = INT_MAX;
    dijkstraBinaryTree(root, 0, &minWeight);

    printf("The shortest path weight from root to any leaf is: %d\n", minWeight);

    return 0;
}
