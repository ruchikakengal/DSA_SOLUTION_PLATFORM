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

// Function to count and display nodes at even indices
void displayEvenIndexNodes(node* head) {
    int count = 0;  // To count how many even-indexed nodes we have
    int index = 0;  // To track the index of the current node

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Nodes at even indices: ");
    node* current = head;  // Use a single pointer to traverse the list
    while (current != NULL) {
        if (index % 2 == 0) {  // Check if the index is even
            printf("%d ", current->data);
            count++;
        }
        current = current->next;  // Move to the next node
        index++;  // Increment the index
    }

    printf("\nTotal number of nodes at even indices: %d\n", count);
}

// Function to print the entire linked list
void printll(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    node* current = head;  // Use a single pointer to traverse the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
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

    // Display nodes at even indices and their count
    displayEvenIndexNodes(head);

    return 0;
}
