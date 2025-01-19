#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

void insertAtTail(Node** head, int val) {
    Node* new_node = createNode(val);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtHead(Node** head, int val) {
    Node* new_node = createNode(val);
    new_node->next = *head;
    *head = new_node;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtHead(&head, 1);
    display(head);

    // Insertion at end
    insertAtTail(&head, 2);
    display(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
