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

You must use place holder, i.e %d

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

To do this we use `scanf` function. This is also in the `stdio.h` library.

