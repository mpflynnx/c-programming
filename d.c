#include <stdio.h>

void add_one(int array[], int length);

int main(void)
{

    int a[] = {2,4,9,1,3,5};
    printf("a: %p\n", a);

    add_one(a, 6);

    for (int i = 0; i < 6; i++)
        printf("a[%d]=%d\n", i, a[i]);

    return 0;
}

void add_one(int array[], int length)
{
    printf("Array passed to function: %p\n", array); 
    for(int i = 0; i < length; i++) array[i] += 1;
}