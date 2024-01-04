## Dynamically allocated memory

Regular variables, arrays and functions are automatically allocated a memory location on the stack. The stack is a term to define how the memory allocation works. Each variable, array or function is stacked on top of the previous, this is contiguous. Therefore an array size cannot be changed, as variables maybe stacked on top of the arrays last index. Variables are removed from the stack automatically when out of scope, functions are removed when they return.

Dynamically allocated memory allows us to create blocks of memory for a given purpose. We can decide what to write to the memory block. This memory block exists on something called the heap.

The C language requires manually memory management, there is no garbage collector as with other languages such as Python or Java. This is a trade off, between performance and automatic memory management. 

To manage dynamically allocated memory we use functions from the `stdlib.h` library. Therefore we must add the include statement.

```c
#include <stdlib.h>
```

These functions are:-

- malloc
- calloc
- realloc
- free

### malloc()
This function is used to create a block of memory on the heap.

Firstly a pointer needs to be created which will store the start address of the memory block.

```c
int *a; // pointer named a
```

**malloc example usage**

```c
a = malloc( sizeof(int) * 5);
```

The above will create a block of memory on the heap to store 5 integers.

`sizeof(int)` determines the space needed to store an integer, we then multiple this by 5. Then pass this size to `malloc` function which in turn returns the memory address of the first integer. 

We can treat this memory block as an array of integers and use array notation to write to the indexes of the array.

```c
a[0] = 1;
a[1] = 2;
a[2] = 3;
a[3] = 4;
a[4] = 5;
```

### calloc()

The `malloc` function only creates the memory block, it doesn't check that the memory block is free of data, or clear the data in that block. The `calloc` function does perform these features in addition to creating the memory block.

**calloc example usage**

```c
a = calloc( 5, sizeof(int));
```

The above will create a block of memory on the heap to store 5 integers.

`5` is the number of integers required to store. `sizeof(int)` determines the space needed to store an integer. Then pass this size to `calloc` function which in turn clears (writes 0's) to 5 memory locations then returns the memory address of the first integer. 

We can treat this memory block as an array of integers and use array notation to write to the indexes of the array.

`calloc` function performs more steps than `malloc` so there is a time penalty for writing 0's to the memory locations.

### free()

It is important for us to clear this memory block when we are done with it. For this we can use the `free` function.

**free example usage**

```c
free(a); // free the memory location pointed to by a
```

The `free` function, frees the memory block on the heap. It doesn't clear or zero the memory locations. This space can then be used for other purposes.

Memory leaks can occur if the pointer value is lost and the memory cannot be reallocated. We could run out of memory, if we never free it. Therefore it is very important to use the free function.

With `malloc` and `calloc` we must first decide how much space to allocate, but what if we want to grow the space. For this we can use the `realloc` function.

### realloc()

The `realloc` function tries to increases the existing memory block, if it cannot grow the existing memory block it will create a new block in memory for the increased size, then copy the existing block into it. 

**realloc example usage**

```c
int *numbers; // pointer
int size = 2; // size of memory
numbers = malloc( sizeof(int) * size);
numbers = realloc(numbers, sizeof(int) * size);
```

We firstly use `malloc` to create a block of memory to store integers at the given size. Function `realloc` can then be used (if required) to grow the memory block by a given size. 

### Finding the average of a set of numbers.

Here is a program that uses `malloc` and `realloc` to ask the user to enter any number of integers. The program initially creates a dynamic memory block on the heap using `malloc` to store just two integers. If the users enters more than two integers the program uses `realloc` to grow the memory block by two. Upon the user entering `-1` the program will then calculate the average of all the integers given, then display the result to the user. By using `realloc` we don't need to limit the numbers or create a block that is too large, we dynamically grow the block as required.

```c
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
```
