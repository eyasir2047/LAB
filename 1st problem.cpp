#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 150

// Define the output file path
const char* OUTPUT_FILE = "/Users/eyasir2047/Desktop/Lab/Lab Exam Mossadak Sir/output.txt";

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the two stacks
    int input_stack[MAX_SIZE], temp_stack[MAX_SIZE];
    int input_top = -1, temp_top = -1;

    // Generate a random input array and push its elements onto input_stack
    for (int i = 0; i < MAX_SIZE; i++) {
        int element = rand() % 1000; // Generate a random integer between 0 and 999
        input_stack[++input_top] = element;
    }

    // Sort the array using the two stacks
    while (input_top >= 0) {
        int current_element = input_stack[input_top--];
        if (temp_top == -1 || current_element >= temp_stack[temp_top]) {
            temp_stack[++temp_top] = current_element;
        } else {
            while (temp_top >= 0 && current_element < temp_stack[temp_top]) {
                input_stack[++input_top] = temp_stack[temp_top--];
            }
            temp_stack[++temp_top] = current_element;
        }
    }

    // Write the sorted array to the output file
    FILE* fout = fopen(OUTPUT_FILE, "w");
    if (fout == NULL) {
        printf("Failed to open output file.\n");
        return -1;
    }
    for (int i = temp_top; i >= 0; i--) {
        fprintf(fout, "%d ", temp_stack[i]);
    }
    fclose(fout);

   // Print the sorted array
    printf("Sorted array: ");
    for (int i = temp_top; i >= 0; i--) {
        printf("%d ", temp_stack[i]);
    }
    printf("\n");

    return 0;
}
