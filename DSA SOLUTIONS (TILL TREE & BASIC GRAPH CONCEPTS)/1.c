#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue (insert) an element at the end of the queue
void enqueue(struct Node** head, int* rear, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) {
        printf("Queue Overflow\n");
        return;
    }

    if (*rear == -1) {  // If the queue is empty
        *head = newNode; // The head points to the new node
    } else {
        struct Node* temp = *head;
        // Traverse to the end of the queue to add the new node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the new node at the end
    }

    (*rear)++;  // Increment rear index
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the front of the queue
int dequeue(struct Node** head, int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = *head;
    int dequeuedData = temp->data;
    *head = (*head)->next; // Move head to the next node

    free(temp);
    (*front)++;  // Increment front index

    if (*front > *rear) {  // If queue is now empty, reset indices
        *front = -1;
        *rear = -1;
    }

    return dequeuedData;
}

// Function to display the elements of the queue
void displayQueue(struct Node* head, int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Points to the front of the queue
    int front = -1, rear = -1; // Front and rear indices
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&head, &rear, element);
                if (front == -1) front = 0;  // Initialize front if queue was empty
                break;
            case 2:
                element = dequeue(&head, &front, &rear);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                displayQueue(head, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
