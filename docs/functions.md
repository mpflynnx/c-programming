## Functions

To make our program more easy to debug, read and to prevent duplicating code. We should create our own functions.

Here is a function that returns the maximum of two integers.

```c
int find_max(int a, int b)
{
    if (a > b) return a;
    else return b;
}
```

- The return value is `int`

- The function name is `find_max`

- The parameters are integers `a` and `b`, these are variables, scoped to the function only.

- The body of the function between {} is where the functions logic is written.

From the programs main function, we call the function `find_max' by passing in arguments to the functions parameters.

The functions return value is used in an expression and result stored to variable `result`.

```c
int main(void)
{
    int result = find_max(10, 12) + 10;
    printf("result: %d\n", result);
    return 0;
}
```

**Output:**
```bash
result: 22
```

**Full program code:**

```c
#include <stdio.h>

int find_max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int main(void)
{
    int result = find_max(10, 12) + 10;
    printf("result: %d\n", result);
    return 0;
}
```

### Variable scope

Variables defined inside {} are only available inside the {}. For example, variables `a` and `b` are not available to `main` function. Variable `result` is not available to `find_max` function.

Variables `a` and `b` have function level or local scope to `find_max` function.

Variable `result` has function level or local scope to `main` function.

Variables cannot be used before there have been declared.

### Function definition 

Functions are typically split into two parts.

1. Function declaration
1. Function definition - function body

This makes the program more readable and prevents the `main` function from being buried depth in the code file.

**Function declaration**
```c
int find_max(int a, int b); // Declaration
```

**Function definition**
```c
int find_max(int a, int b)
{
    if (a > b) return a;
    else return b;
}
```

**Full program code:**

```c
#include <stdio.h>

int find_max(int a, int b);

int main(void)
{
    int result = find_max(10, 12) + 10;
    printf("result: %d\n", result);
    return 0;
}

int find_max(int a, int b)
{
    if (a > b) return a;
    else return b;
}
```

The `main` function is now more prominent in the code, and the `find_max` function now appears below the `main` function.

### Void functions

A void function is a function that returns no value. Used to accept inputs from user or print text.

`void` function declaration:

```c
void print_two(float a, float b);
```

**Full program:**
```c
#include <stdio.h>

void print_two(float a, float b);

int main(void)
{

    float x = 2.5;
    float y = 4.2;
    print_two(x, y);
    return 0;
}

void print_two(float a, float b)
{
    printf("%f\n%f\n", a, b);
    // No return needed.
}
```

### Passing arrays to functions

We have seen that to create an array and assign values to it, we can use: -

```c
int a[] = {2,4,9,1,3,5};
```

In `C programming` this array `a` is not a variable that can be used in an expression, but a memory address in the computers memory.

Printing `a` as shown below will output a hexadecimal number which is the memory address. The `%p` refers to the placeholder for a `pointer`.

```c
printf("a: %p\n", a);
```

**Output**
```bash
a: 0x7ffe9d685b70
```

To print the contents of an array, we need to iterate through every element and print the value.

```c
for (int i = 0; i < 6; i++)
    printf("a[%d]=%d\n", i, a[i]);
```

**Ouput:**
```bash
a[0]=2
a[1]=4
a[2]=9
a[3]=1
a[4]=3
a[5]=5
```

When we pass an array to a function we are passing the memory address (pointer) of the array.

```c
void add_one(int array[], int length)
{
    printf("array: %p\n", array); 
    for(int i = 0; i < length; i++) array[i] += 1;
}
```
The function above, takes in an array memory address and iterates through every index, incrementing the index value. 

**Note** this may not be the desired outcome, as we may not always want to update the arrays contents.

Putting this all together we have the program below:

```c
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
```

**Output:**
```bash
a: 0x7ffd1bccf360
Array passed to function: 0x7ffd1bccf360
a[0]=3
a[1]=5
a[2]=10
a[3]=2
a[4]=4
a[5]=6
```