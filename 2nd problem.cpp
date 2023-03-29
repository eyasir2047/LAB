#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 150
#define NUM_BUCKETS 15

// Define the output file path
const char* OUTPUT_FILE = "/Users/eyasir2047/Desktop/Lab/Lab Exam Mossadak Sir/output2.txt";

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of a linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    // Create the two stacks and the linked list
    int input_stack[MAX_SIZE], temp_stack[MAX_SIZE];
    int input_top = -1, temp_top = -1;
    struct Node* sLink = NULL;

    // Push all the elements of the unsorted array onto input_stack
    for (int i = 0; i < MAX_SIZE; i++) {
        int element = rand() % 1000; // Generate a random integer between 0 and 999
        input_stack[++input_top] = element;
    }

    // Sort the array using the two stacks and store the sorted elements in sLink
    while (input_top >= 0) {
        int current_element = input_stack[input_top--];
        if (temp_top == -1 || current_element >= temp_stack[temp_top]) {
            temp_stack[++temp_top] = current_element;
        } else {
            while (temp_top >= 0 && current_element < temp_stack[temp_top]) {
                insertAtBeginning(&sLink, temp_stack[temp_top--]);
            }
            temp_stack[++temp_top] = current_element;
        }
    }
    while (temp_top >= 0) {
        insertAtBeginning(&sLink, temp_stack[temp_top--]);
    }

    // Create an array of pointers to nodes to use as the buckets
    struct Node* buckets[NUM_BUCKETS] = {NULL};

    // Traverse sLink and insert each node into the appropriate bucket
    struct Node* current = sLink;
    while (current != NULL) {
        int bucket_idx = current->data / 100;
        insertAtBeginning(&buckets[bucket_idx], current->data);
        current = current->next;
    }

    // Concatenate the buckets back into sLink in order
    sLink = NULL;
    for (int i = NUM_BUCKETS - 1; i >= 0; i--) {
        struct Node* bucket = buckets[i];
        while (bucket != NULL) {
            insertAtBeginning(&sLink, bucket->data);
            bucket = bucket->next;
        }
    }

    // Write the sorted linked list to the output file
    FILE* fout = fopen(OUTPUT_FILE, "w");
    if (fout == NULL) {
        printf("Failed to open output file.\n");
        return -1;
    }
    current = sLink;
    while (current != NULL) {
        fprintf(fout, "%d ", current->data);
        current = current->next;
    }
    fclose(fout);

    // Print the sorted linked list
    printf("Sorted linked list: ");
    current = sLink;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
/*
Certainly! This code is an implementation of the bucket sort algorithm on a linked list. Here's how it works:

We start by creating two stacks (input_stack and temp_stack) and a linked list (sLink).
We push all the elements of a random unsorted array onto input_stack.
We sort the elements of input_stack using the two stacks and store the sorted elements in sLink.
We create an array of pointers to nodes (buckets) to use as the buckets for the bucket sort algorithm. We also initialize each bucket to be empty.
We traverse sLink and insert each node into the appropriate bucket based on its value. Specifically, we use the node's data value divided by 100 (integer division) to determine the bucket index. For example, a node with data value 476 would be placed in bucket 4.
We concatenate the buckets back into sLink in order. Specifically, we start with the highest-indexed bucket and work our way down to bucket 0, and for each bucket, we insert its nodes at the beginning of sLink.
Finally, we print the sorted linked list and write it to an output file.
Note that this implementation assumes that the input array contains only non-negative integers. If the input array could contain negative integers, the bucket indices would need to be adjusted accordingly.





*/