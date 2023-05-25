#include <stdio.h>
#include <stdlib.h>

// Structure for each node of the linked list
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

// Function to insert a node at the beginning of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to swap data between two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Bubble sort implementation using linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr;
    struct Node* lptr = NULL;
    
    // Check for empty list
    if (head == NULL)
        return;
    
    do {
        swapped = 0;
        ptr = head;
        
        // Traverse the linked list
        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    // Insert elements into the linked list
    insertNode(&head, 6);
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 9);
    insertNode(&head, 3);
    
    printf("Original list: ");
    printList(head);
    
    // Sort the linked list using bubble sort
    bubbleSort(head);
    
    printf("Sorted list: ");
    printList(head);
    
    return 0;
}
