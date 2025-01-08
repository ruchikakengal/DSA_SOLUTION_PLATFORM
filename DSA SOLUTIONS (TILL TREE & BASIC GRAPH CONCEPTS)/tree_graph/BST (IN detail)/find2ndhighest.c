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

// Function to find the node with the second-highest value
Node* findSecondHighest(Node* root) {
    if (!root || (!root->left && !root->right)) {
        printf("Tree must have at least two nodes.\n");
        return NULL;
    }

    Node* current = root;
    Node* parent = NULL;

    // Traverse to the rightmost node (highest value)
    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }

    // Case 1: If the rightmost node has a left subtree
    if (current->left != NULL) {
        Node* temp = current->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    // Case 2: If the rightmost node does not have a left subtree
    return parent;
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
    root = insert(root, 25);
    root = insert(root, 35);

    printf("In-order Traversal of the BST:\n");
    inOrder(root);
    printf("\n");

    // Find the second-highest node
    Node* secondHighest = findSecondHighest(root);
    if (secondHighest) {
        printf("The second-highest node is: %d\n", secondHighest->data);
    }

    return 0;
}
