## Global scope variables

If you initialise a variable outside of any function, then the variable is global. This is known as `global` or file `scope`.

```c
#include <stdio.h>
#include <stdlib.h>

int x = 10;
```

The variable can be used by all functions. Variable `x` can  also be modified by any function.

```c
#include <stdio.h>
#include <stdlib.h>

int x = 10;

void func();

int main(int argc, char *argv[])
{
    x++; // x = 11
    printf("main x: %d\n", x);
    func();
    return 0;
}

void func()
{
    x++; // x = 12
    printf("func x: %d\n", x);
}
```

**Output**
```bash
main x: 11
func x: 12
```

As best practice it is advisable to **NOT** use global variables this way, as this can led to difficulty reading and debugging the program.

### Matching global scoped and function scoped variable names
By default function scoped variable names take precedence over global scoped variable names.

```c
int x = 10;

int main(int argc, char *argv[])
{
    int x = 20;
    printf("main x: %d\n", x);
    return 0;
}
```

**Output**
```bash
main x: 20;
```

This is another good reason to not use global variables.
