# c-programming-for-beginners

## Hello, World first C Program

Create a new file named `d.c`.

```c
/*
multi line comment usually at top of file.
*/

#include <stdio.h>  // import statement for use of  printf function

// is a single line comment

int main(void) // main function
{
    // main function body inside {}
    printf("Hello World\n"); // pass argument string "Hello World\n" to printf function
    printf("Line 2!\n"); // \n = newline character
    printf("Line 3!\n");
    return 0;
}
```

Compile file `d.c` to create new file `d`

Open terminal and type:
```bash
$ gcc -o d d.c
```

Execute file `d`.

```bash
$ ./d
```

Expected output

```bash
$ ./d
Hello World
$
```

## Input Processing Output (IPO) Model example

Declare a integer variable named `speed`

```c
int speed;
```

Assign value to variable, initalise the variable.

```c
int speed = 20; // km
```

Assign value to variable time, initalise the variable.

```c
int time = 7; // hours
```

Use expression to calcaulate distance

```c
int distance = speed * time; // 140
```

Output results of distance variable.

In c you cannot do this:

printf(distance); // invalid in c

You must use place holder, i.e `%d`. `%d` means integer.

```c
printf("dist: %d\n", distance)
```

Compile file `d.c` to create new file `d`

Open terminal and type:
```bash
$ gcc -o d d.c
```

Execute file `d`.

```bash
$ ./d
```

Expected output

```bash
$ ./d
distance: 140
$
```

This approach means if we change the variable values the program needs to be recompiled.

A better approach is to ask the user for the variable values speed and time, then the program can output the result for different values without needing to be recompiled.

To do this we can use `scanf` function. This is also in the `stdio.h` library.

Other functions exist that do similar to `scanf`.

`scanf` works similar to `printf` but backward.

We first have to initialise the variables `speed` and `time`.
It is best practice to assign a value to variables, even if the value will be updated by the user. This initialising a variable with a value, creates a space in memory and overwrites any previous data in that memory location. In our example we are defining integer variables so we should assign the value 0 to the variables.

```c
    int speed = 0;
    int time = 0;
```

Ask user to enter value for speed.

```c
    // Ask user for value of speed
    printf("Enter value for speed: ");
    // Expects integer %d from input, will assign to speed variable using & operator.
    scanf("%d", &speed);
```

Ask user to enter value for time.

```c
    printf("Enter value for time: ");
    // Expects integer %d from input, will assign to time variable using & operator.
    scanf("%d", &time);
```

Recompile and run program.

Expected output

```bash
$ ./d
Enter value for speed: 4
Enter value for time: 5
distance: 20
$
```

Program can be run multiple times with user entering different values without need for recompilation.

## Variable types and using printf & scanf

### `double` and `float` variables.

`float` is short hand for floating point value, allows us to store real numbers. That is numbers with decimal places. 0 is also a `float`.

```c
float x = 5.2;
```

`double` is very similar to a float.

```c
double y = -9.8;
```

`double` can store numbers with a higher level of precision, i,e more accuracy. `double` has a greater range, more decimal places. Better for high accuracy calculations, but uses more computer memory.

Using the `scanf` function with floats. Placeholder for `float` is `%f`. 

```c
printf("x: ");
scanf("%f, &x); // store float in variable x
```


Using the `printf` function with floats. Placeholder for `float` is `%f`. 

```c
printf("x: %f\n", x);
```

```c
#include <stdio.h>

int main(void)
{

    float x = 5.2;
    double y = -9.8;

    printf("Enter value for x: ");
    scanf("%f", &x); // Get float from user assign to x
    printf("x: %f\n", x); // print x

}
```
Compile file `d.c` to create new file `d`

Open terminal and type:
```bash
$ gcc -o d d.c
```

Execute file `d`.

```bash
$ ./d
```

Expected output

```bash
$ ./d
Enter value for x: 5.2
x: 5.200000
```

Notice the output `5.200000` we can use modifiers to change the appearance.

`float` does not store the exact number given. See below:

```bash
$ ./d
Enter value for x: -52.245
x: -52.244999
```

This is due to the way the computer stores the number in memory. It cannot store exactly the 52.245 but it is very very close.

To use `double` with `scanf` we use the placeholder `%lf` large float.

To use `double` with `printf` we can also user `%lf` but `%f` will also work.

```c
    printf("Enter value for y: ");
    scanf("%lf", &y); // Get double from user assign to y
    printf("y: %lf\n", y); // print y

}
```

Recompile and run program.

Expected output

```bash
$ ./d
Enter value for x: 20.2
x: 20.200001
Enter value for y: -10.88
y: -10.880000
```

### char variable

`char` variable. For storing characters, must be assigned in single quotes. char are fundamentally integer values. Using the ASCII code which is a integer. For example the ASCII code for `d` is 100.

```c
char c = 'd';
```

### `printf` and `scanf` with char variables.

`%c` is the placeholder for using char variables.

```c
    printf("c: ");
    scanf("%c", &c);
    printf("c: %c\n", c);
}
```

Can also use `%d` which in normally for integers. To print the ASCII integer value of the character `d` i.e 100.

```c
    printf("c: %d\n", c);
```

Compile and run program.

Expected output.

```bash
$ ./d
c: d
c: d
c: 100
```

## Arithmetic operators

We have use literal values for `int`, `float`, `double` and `char`.

We can declare and initialise variables on a single line, separated by a comma.

```c
double x =5.2, y = 2.5;
```

### Common operators: `*`,`y`, `/`, `-`

```c
double multiple = x * y;
double addition = x + y;
double division = x / y;
double subtraction = x - y;
```

### modulus operator `%`

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