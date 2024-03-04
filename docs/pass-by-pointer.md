## Pass by pointer

Pass by pointer also known as pass by reference.

We can pass a pointers value to a function. The function can then use the variable pointed to by the passed in pointer.

```c
#include <stdio.h>

void add_one(int *a); // pass memory address to function

int main(void)
{
    int b = 5;
    printf("&b: %p\n", &b); // prints b memory address
    add_one(&b); // pass memory address to function
    printf("b: %d\n", b); // prints updated variable value

    return 0;
}

void add_one(int *a)
{
    printf("a: %p\n", a);
    *a = *a + 1; // Dereference pointer value to obtain integer, then add one
}
```

**Output:**
```bash
&b: 0x7ffe2ac5e614
a: 0x7ffe2ac5e614
b: 6
```

We have updated the value of b in place from the main function by calling the `add_one` function and passing in the memory address of variable `b`.

This is very powerful. In the example program below we can update multiple variables with one function call. Usually a function can only return one return value.

```c
#include <stdio.h>

void add_one(int *a, int *b, int *c);

int main(void)
{

    int x1 = 1, x2 = 2, x3 = 3;
    add_one(&x1, &x2, &x3); // Update three variables in place.
    printf("x1: %d\n", x1);
    printf("x2: %d\n", x2);
    printf("x3: %d\n", x3);

    return 0;
}

void add_one(int *a, int *b, int *c)
{
    *a = *a + 1; // 1 + 1 = 2
    *b = *b + 1; // 2 + 1 = 3
    *c = *c + 1; // 3 + 1 = 4
}
```

**Output:**
```bash
x1: 2
x2: 3
x3: 4
```