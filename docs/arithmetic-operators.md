## Arithmetic operators

We have use literal values for `int`, `float`, `double` and `char`.

We can declare and initialise variables on a single line, separated by a comma.

```c
double x =5.2, y = 2.5;
```

### Common operators

```c
double multiple = x * y;
double addition = x + y;
double division = x / y;
double subtraction = x - y;
```

### modulus operator %

```c
int x = 11, y = 3;

int div = x / y;

printf("div: %d\n", div);
```

3 goes into 11, 3 times. With a remainder of 2.

Expected output:

```bash
div: 3
```

Modulus `%` operator returns the remainder which is 2.

```c
int x = 11, y = 3;

int mod = x % y;
```

```c

#include <stdio.h>

int main(void)
{

    int x = 11, y = 3;

    int div = x / y;
    int mod = x % y;

    printf("div: %d\n", div);
    printf("mod: %d\n", mod);

    return 0;

}
```

Expected output:

```bash
div: 3
mod: 2
```

This can be used to determine if a number is either odd or even.

```c
    int x = 11;

    int mod = x % 2;
```

If mod = 1, x is a odd number.

```c
    int x = 12;

    int mod = x % 2;
```

If mod = 0, x is a even number.

```c
#include <stdio.h>

int main(void)
{

    int x = 14;

    int mod = x % 2;

    printf("mod: %d\n", mod);

    return 0;

}
```

Expected output:

```bash
mod: 0
```