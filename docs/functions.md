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
