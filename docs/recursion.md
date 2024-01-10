## Recursion

Recursion is a way of solving a problem where our solution depends on solutions to smaller instances of the same problem. Practically, this is functions calling themselves.

A good example for using recursion is for finding the [factorial](https://en.wikipedia.org/wiki/Factorial) of a number. 

The factorial of `n` denoted by `n!` is the product of all positive integers <=`n`.

n! = n * (n-1) * (n-2) ... * 1

**example**
Find factorial of 5.

5 factorial = 5 * 4 * 3 * 2 * 1 = 120

### Finding the factorial of n (iterative solution)

```c
#include <stdio.h>

int main(void)
{

    int n = 0;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n >= 1)
    {
        fact = n * fact;
        n--;
    }

    printf("Factorial is: %d\n", fact);

    return 0;
}
```

### Finding the factorial of n (recursive solution)

A recursive solution for finding a factorial of a number is very close match to the mathematical definition of the problem, this make the code more readable.

**Mathematic description**

n! = n * (n-1) * (n-2) ... * 1

**C code**
```c
n * factorial(n - 1);
```

#### Recursive flow

factorial(5)

5 * (5 - 1)

5 * factorial(4)

5 * (4 - 1)

5 * 4 * factorial(3)

5 * (3 - 1)

5 * 4 * 3 * factorial(2)

5 * (2 - 1)

5 * 4 * 3 * 2 factorial(1) 

Base case is to stop the recursion when n = 1.

Recursion should be used with caution, as functions calling themselves may exceed the memory capacity of the computer.

Recursion is a great solution to use to help solve data structure and algorithms.

### Finding the factorial of n (recursive solution)

```c
#include <stdio.h>

long int factorial(int n);

int main(void)
{

    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %ld\n", n, factorial(n));

    return 0;
}

long int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n-1);
}
```

**Note:** Doesn't appear to work for numbers greater than 20.