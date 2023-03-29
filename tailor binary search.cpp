#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 15

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert node at the beginning of the linked list
void insertNode(Node** headRef, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Traverse the linked list and print the values
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Pop all elements from the stack and insert them at the beginning of the linked list
void popStack(Node** headRef, int stack[], int* top) {
    while (*top >= 0) {
        insertNode(headRef, stack[*top]);
        (*top)--;
    }
}

// Custom binary search to find the average of the first and last element
int binarySearch(Node* head, float target) {
    int low = 0, high = 0;
    Node* current = head;
    
    // Find the length of the linked list
    while (current->next != NULL) {
        high++;
        current = current->next;
    }
    
    // Set the high index to the last index
    high--;
    
    // Binary search loop
    while (low <= high) {
        int mid = (low + high) / 2;
        current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }
        float average = (float)(head->data + current->data) / 2;
        if (average == target) {
            return 1;
        } else if (average < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
    // Initialize the stack and linked list
    int stack[BUCKET_SIZE];
    int top = -1;
    Node* sLink = NULL;
    
    // Push elements onto the stack
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int num = rand() % 100;
        stack[++top] = num;
    }
    
    // Pop elements from the stack and insert them into the linked list
    popStack(&sLink, stack, &top);
    
    // Sort the linked list using bucket sort algorithm
    // ...
    
    // Find if average of first and last element is available in the linked list
    float target = (float)(sLink->data + current->data) / 2;
    if (binarySearch(sLink, target)) {
        printf("Average of first and last element is found in the linked list.\n");
    } else {
        printf("Average of first and last element is not found in the linked list.\n");
    }
    
    // Print the linked list
    printf("Linked list: ");
    printList(sLink);
    
    return 0;
}
