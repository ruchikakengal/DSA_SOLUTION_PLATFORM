#include<stdio.h>
#include<stdlib.h>

// Definition of the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node and insert it at the beginning of the linked list
void createnode(node **head) {
    int data;
    node* newnode = (node*)malloc(sizeof(node));
    
    if (newnode == NULL) {  // Check for malloc failure
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = *head;  // Point new node to the current head
    *head = newnode;        // Move head to point to the new node
}

// Function to sort the linked list in ascending order using data swapping
void sortAscending(node **head) {
    if (*head == NULL) {
        printf("Empty linked list.\n");
        return;
    }

    node *p, *q;
    int temp;

    
    for (p = *head; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->data > q->data) {
                // Swap data between nodes p and q
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

// Function to print the linked list
void printll(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int num = 1;
    node *head = NULL;

    // Keep inserting nodes while the user wants
    while (num) {
        createnode(&head);
        printf("Want to insert more? Type 1 for yes, 0 for no: ");
        scanf("%d", &num);
    }

    // Sort the list in ascending order
    sortAscending(&head);

    // Print the sorted linked list
    printll(head);

    return 0;
}
