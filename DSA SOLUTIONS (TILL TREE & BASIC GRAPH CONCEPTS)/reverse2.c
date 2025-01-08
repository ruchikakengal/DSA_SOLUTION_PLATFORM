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



// Function to reverse a linked list by swapping data
void reverseListDataSwap(struct Node* head) {
    if (head == NULL) return;
   int len=0;
   struct Node*tempp=head;
   while(tempp!=NULL){
    len++;
    tempp=tempp->next;
   }

    
    struct Node* left = head;
    struct Node* right = head;
    struct Node* prev = head;

    while(right->next!=NULL){
      right=right->next;
    }

    int temp=0;
    for (int i = 0; i < len / 2; i++) {
        temp = left->data;
        left->data = right->data;
        right->data = temp;

       
        left = left->next;
       prev=head;
       while(prev->next!=right){
        prev=prev->next;

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

