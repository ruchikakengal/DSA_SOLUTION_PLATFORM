#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to find the Lowest Common Ancestor (LCA) of two nodes
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    // If both n1 and n2 are smaller than root, LCA is in the left subtree
    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    // If both n1 and n2 are greater than root, LCA is in the right subtree
    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    // Otherwise, this is the LCA node
    return root;
}

// Function to count nodes from root to a target node
int countNodesToTarget(Node* root, int target) {
    int count = 0;

    while (root != NULL) {
        count++;
        if (target < root->data) {
            root = root->left;
        } else if (target > root->data) {
            root = root->right;
        } else {
            break;  // Found the target node
        }
    }

    return count;
}

// Function to calculate the total common parent count between two nodes
int commonParentCount(Node* root, int n1, int n2) {
    Node* lca = findLCA(root, n1, n2);
    if (lca == NULL) {
        printf("One or both nodes are not present in the tree.\n");
        return -1;
    }

    // Count nodes to the LCA from root
    return countNodesToTarget(root, lca->data);
}

// In-order traversal to print the BST
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int nodes[] = {20, 10, 30, 5, 15, 25, 35};
    int size = sizeof(nodes) / sizeof(nodes[0]);

    // Build BST
    for (int i = 0; i < size; i++) {
        root = insert(root, nodes[i]);
    }

    printf("In-order traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    int n1, n2;
    printf("Enter two nodes to find their common parent count: ");
    scanf("%d %d", &n1, &n2);

    int count = commonParentCount(root, n1, n2);
    if (count != -1) {
        printf("Common parent count for nodes %d and %d is: %d\n", n1, n2, count);
    }

    return 0;
}
