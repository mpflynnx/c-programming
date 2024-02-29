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

Once the first matching case is found then subsequent case statements are also executed. This is known as fall through logic. We can prevent this using `break;` statement as shown.

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

### Using fall through logic

As seen once the first match has been found the subsequent case statement are executed.

Here is a program which will count the number of `a` letters and the number of vowels in a string.

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char s[] = "aeioxyz";

    int length = strlen(s);

    int a = 0;
    int vowel = 0;

    for (int i = 0; i < length; i++)
    {
        switch (toupper(s[i])) 
        {
            case 'A':
                a++;
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel++;
        }
    }

    printf("a: %d, vowels: %d\n", a, vowel);
}
```

**Output**
```bash
a: 1, vowels: 4
```

No break statements are used, the vowel counter is incremented when s[i] contains a vowel.

Some programmers favour `If` statements as they are easily to understand and can provide the same functionality.