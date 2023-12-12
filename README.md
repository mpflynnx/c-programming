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