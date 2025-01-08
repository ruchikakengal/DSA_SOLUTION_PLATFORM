#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create and insert a new node at the beginning of the linked list
node* createnode(node* head) {
    int data;
    node* newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) {  // Check for malloc failure
        printf("Memory allocation failed!\n");
        return head;  // Return the current head if allocation fails
    }

    printf("Enter value: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = head;  // Insert the new node at the beginning
    return newnode;        // Return the new head of the list
}

// Function to count and display even nodes in the linked list
void displayEvenNodes(node* head) {
    int count = 0;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Even nodes: ");
    node* current = head;  // Use a single pointer to traverse
    while (current != NULL) {
        if (current->data % 2 == 0) {  // Check if the node data is even
            printf("%d ", current->data);
            count++;
        }
        current = current->next;  // Move to the next node
    }

    printf("\nTotal number of even nodes: %d\n", count);
}

// Function to print the entire linked list
void printll(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    node* current = head;  // Use a single pointer to traverse
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;  // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    int num = 1;
    node* head = NULL;  // Head pointer to the linked list

    // Create the linked list
    while (num) {
        head = createnode(head);  // Insert new node and update head
        printf("Want to insert more? Type 1 for yes, 0 for no: ");
        scanf("%d", &num);
    }

    // Display the entire linked list
    printll(head);

    // Display the even nodes and their count
    displayEvenNodes(head);

    return 0;
}
