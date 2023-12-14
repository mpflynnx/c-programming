## For loops

For loops provide a more concise way of iterating. 

A `For loop` is made up an initialise statement, this sets up the counter variable.

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

 Note: The `i` variable only exists inside the `For loop`. This is know as a variables scope.

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