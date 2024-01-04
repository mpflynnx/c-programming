#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *numbers; // pointer to memory block to store numbers
    int size = 2; // Initial size of memory block
    numbers = malloc( sizeof(int) * size); // Create memory block for 2 integers
    int input = 0; // Initial user input
    int i = 0; // Counter for keeping track of the number of integers given by user

    do 
    {
        // Grow memory block, if number of integers given, exceeds existing block size
        if (i == size)
        {
            size += 2; // Grow memory by 2
            numbers = realloc(numbers, sizeof(int) * size); // Use realloc to grow memory block
            printf("Realloc for %d integers\n", size);
        }
        printf("Enter (-1 to quit): ");
        scanf("%d", &input);
        if (input != -1) // Check for -1 entered by user
        {
            numbers[i] = input; // store given integer in memory
            i++; // Keep track of number of integers
        }
    } while ( input != -1);

    // calculate average of all integers given
    int num_elements = i;
    int total = 0;
    for (int j = 0; j < num_elements; j++)
        total +=numbers[j];

    printf("average: %d\n", total / num_elements);

    // free up the memory
    free(numbers);

    return 0;
}
