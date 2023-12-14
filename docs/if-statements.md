## If statements

### Control structures
Alters the flow of the program. 

Using a if statement to display the text "Pass", if `grade` greater than or equal to `50`.

```c
#include <stdio.h>

int main(void)
{

    int grade = 0;

    printf("Grade: ");
    scanf("%d", &grade);

    if (grade >= 50)
        printf("Pass\n");

    return 0;

}
```

Expected result:

```bash
Grade: 55
Pass
```

If `grade` less than `50` then nothing happens.

A condition is something that is true or false.

`>=` is known as a relational operator.

```c
grade >= 50;
```

Will execute anything inside block, denoted by {}. If condition is true.

```c
    if (grade >= 50)
    {
        // if true execute this block
        printf("Pass\n");
        printf("Congrats!\n");
    }

    // if false do not execute block
    printf("If statement done.")
```

If  the condition false, do not execute block.

Expected output:

```bash
Grade: 44
If statement done.
```

### else statement

if else control structures

Handles the execution of the program when the if condition is false.

```c
    if (grade >= 50)
    {
        // if true execute this block
        printf("Pass\n");
        printf("Congrats!\n");
    }
    else 
    {
        printf("Fail\n");
    }

    printf("If else statements done.\n");
```

```bash
Grade: 44
Fail
If statement done.
```

### if else if statements

Check for multiple conditions.

```c
    if (grade >= 90) printf("A\n");
    else if (grade >= 80) printf("B\n");
    else printf("Other\n");
```

Expected result:

```bash
Grade: 91
A

Grade: 81
B

Grade: 71
Other
```

You can use as many else if statements as is necessary.

Can also use {} to format the syntax of else if