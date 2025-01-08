#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        // If the list is empty, the new node points to itself
        newNode->next = newNode;
        return newNode;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert the new node at the end and update the last node's next
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to delete a node from the circular linked list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node *curr = head, *prev = NULL;

    // Case 1: If the node to be deleted is the head
    if (head->data == key) {
        // Find the last node
        while (curr->next != head) {
            curr = curr->next;
        }
        if (curr == head) {
            // Only one node in the list
            free(head);
            return NULL;
        }
        // Point the last node to the next of head
        curr->next = head->next;
        free(head);
        return curr->next;
    }

    // Case 2: For nodes other than the head
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Key not found in the list.\n");
    return head;
}

// Function to display the circular linked list
void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Circular Linked List:\n");
    printCircularList(head);

    // Delete a node from the circular linked list
    printf("Deleting node with data 20:\n");
    head = deleteNode(head, 20);
    printCircularList(head);

    // Delete the head node
    printf("Deleting node with data 10 (head node):\n");
    head = deleteNode(head, 10);
    printCircularList(head);

    return 0;
}
