#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int *array;
} Info;

int main(void)
{

    Info a;
    a.data = 7;
    a.array = malloc(sizeof(int) * 5);

    // assign values to a.array
    for (int i = 0; i < 5; i++)
        a.array[i] = i + 1;

    Info b = a;
    a.data = 8; // Update a.data

    printf("b.data: %d\n", b.data); // 7

    // print b.array
    for (int i = 0; i < 5; i++)
        printf("b.array[%d] = %d\n", i, b.array[i]);

    // assign new values to a.array
    for (int i = 0; i < 5; i++)
        a.array[i] = i + 2;

    // print b.array
    for (int i = 0; i < 5; i++)
        printf("b.array[%d] = %d\n", i, b.array[i]);

    printf("a.array: %p\n", a.array);
    printf("b.array: %p\n", b.array);

    free(a.array);
    return 0;
}