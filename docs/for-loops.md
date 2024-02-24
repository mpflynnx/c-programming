## For loops

For loops provide a more concise way of iterating. 

A `for` loop is made up of an initialise statement, this sets up the counter variable.

```c
int i = 0;
```

A condition statement, tests for counter variable.

```c
i < 5;
```

Update statement, increments the counter variable.

```c
i++
```

All on one line:

```c
for (int i = 0; i < 5; i++)
```

 Note: The `i` variable only exists inside the `for` loop. This is know as a variables scope.

### Simple For loop example
```c
#include <stdio.h>

int main(void)
{

    for (int i = 0; i < 5; i++)
        printf("i: %d\n", i);
    return 0;

}
```

Output:
```bash
i: 0
i: 1
i: 2
i: 3
i: 4
```

### for loop with break

The `break` keyword can be used inside a `for` loop block. This will end the iteration when a condition is true.

```c
for (int i = 0; i < 5; i++)
{
    printf("i: %d\n", i);
    if (i == 2) break; // loop ends when i == 2
}
```

**Output**
```bash
i: 0
i: 1
i: 2
```

### for loop with continue

The `continue` keyword can be used inside a `for` loop block. This will skip over the loop body when a condition is true, and restart the iteration.

```c
for (int i = 0; i < 5; i++)
{
    if (i == 2) continue; // skips the remaining when i == 2
    printf("i: %d\n", i); // skipped if i == 2
}
```

**Output**
```bash
i: 0
i: 1
i: 3
i: 4
```