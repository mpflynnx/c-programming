#include <stdio.h>

struct Foo1
{
    short a; // will have 2 bytes of padding after a
    int b;
    short c; // will have 2 bytes of padding after c
};

struct Foo2
{
    int b;
    short a;
    short c;
};

int main()
{
    struct Foo1 foo1 = {0,0,0}; // prints 12
    struct Foo2 foo2 = {0,0,0}; // prints 8

    printf("The size of Foo1 is %ld bytes\n", sizeof(foo1));
    printf("The size of Foo2 is %ld bytes\n", sizeof(foo2));

    return 0;
}

void add_one(int array[], int length)
{
    printf("Array passed to function: %p\n", array); 
    for(int i = 0; i < length; i++) array[i] += 1;
}