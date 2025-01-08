#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the node structure
typedef struct node {
    char data[100];  // Array to store strings
    struct node* next;
} node;

// Function to create a new node and insert it at the beginning of the linked list
void createnode(node** head) {
    char str[100];
    node* newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) {  // Check for malloc failure
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter a string: ");
    scanf("%s", str);  // Read string input

    strcpy(newnode->data, str);  // Copy string to the new node
    newnode->next = *head;  // Point new node to the current head
    *head = newnode;        // Move head to point to the new node
}

// Function to sort the linked list in alphabetical order using data swapping
void sortAscending(node** head) {
    if (*head == NULL) {
        printf("Empty linked list.\n");
        return;
    }

    node* p;
    node* q;
    char temp[100];

    // Bubble sort algorithm to sort the linked list
    for (p = *head; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->data, q->data) > 0) {  // Compare strings
                // Swap strings between nodes p and q
                strcpy(temp, p->data);
                strcpy(p->data, q->data);
                strcpy(q->data, temp);
            }
        }
    }
}

// Function to print the linked list
void printll(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int num = 1;
    node* head = NULL;

    // Keep inserting nodes while the user wants
    while (num) {
        createnode(&head);
        printf("Want to insert more? Type 1 for yes, 0 for no: ");
        scanf("%d", &num);
    }

    // Sort the list in alphabetical order
    sortAscending(&head);

    // Print the sorted linked list
    printll(head);

    return 0;
}
