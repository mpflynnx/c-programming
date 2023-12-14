## Switch statements

Similar to an `If` statements except there is no condition to test for. We can provide a variable `number` and when the value of `number` matches the `case` the code for that `case` is executed.

In the example below, integer variable `number` is assigned 0. When the switch statement case matches `number` the printf statement is executed.

```c
#include <stdio.h>

int main(void)
{

    int number = 0;

    switch (number) 
    {
        case 0:
            printf("Case 0!\n");
        case 1:
            printf("Case 1!\n");
    }

    return 0;
}
```

Output:

```bash
Case 0!
Case 1!
```

Once the first matching case is found then subsequent case statements are also executed. This is known as full through logic. We can prevent this using `break;` statement as shown.

```c
#include <stdio.h>

int main(void)
{

    int number = 0;

    switch (number) 
    {
        case 0:
            printf("Case 0!\n");
            break;
        case 1:
            printf("Case 1!\n");
            break;
    }

    return 0;
}
```

Using the `break` statement will exit the switch statement.

Output:

```bash
Case 0!
```

We can define a `default` case. This case will always execute if none of the other cases match.

```c
#include <stdio.h>

int main(void)
{

    int number = 2;

    switch (number) 
    {
        case 0:
            printf("Case 0!\n");
            break;
        case 1:
            printf("Case 1!\n");
            break;
        default:
            printf("Default case!\n");
    }

    return 0;
}
```

Output:

```bash
Default case!
```

As the `default` is last is doesn't need a `break`.

Some programmers favour `If` statements as they are easily to understand and can provide the same functionality.