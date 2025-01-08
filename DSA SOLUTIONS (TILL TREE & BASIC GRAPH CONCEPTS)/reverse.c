#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the length of the linked list
int listLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse a linked list by swapping data
void reverseListDataSwap(struct Node* head) {
    if (head == NULL) return;

    int len = listLength(head);
    struct Node* left = head;
    struct Node* right = head;

    // Move 'right' pointer to the last node
    for (int i = 0; i < len - 1; i++) {
        right = right->next;
    }

    // Swap data between left and right nodes
    for (int i = 0; i < len / 2; i++) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        // Move 'left' to the next node and 'right' back to the previous node
        left = left->next;

        // Move 'right' to the previous node
        struct Node* prev = head;
        for (int j = 0; j < len - i - 2; j++) {
            prev = prev->next;
        }
        right = prev;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    // Reverse the list using data swapping
    reverseListDataSwap(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}

