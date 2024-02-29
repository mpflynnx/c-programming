## Command-line arguments

We can allow our programs to accept command-line arguments from the bash shell and use them to alter the programs flow or as input parameters for program features.

To accept command-line arguments the main function needs to accept some parameters.

```c
int main(int argc, char *argv[])
{
    ...
}
```
`int argc` contains the numbers of arguments including the command to execute the program, i.e `./d` in our examples. Therefore, by default `int argc` is always 1. 

If we use four command line arguments, as shown.
```bash
$ ./d 1 2 3 4
```
`int argc` in this case would be 5. 

`char *argv` is an array of strings that can be accessed to retrieve the command line arguments.

For example to print out the index 1 of `argv` array.

```c
printf("argv[1] = %s\n", argv[1]);
```

**Output**
```bash
argv[1] = 1
```
To print all elements in the array.

```c
for (int i = 0; i < argc; i++)
    printf("argv[%d] = %s\n", i, argv[i]);
```

**Output**
```bash
argv[0] = ./d
argv[1] = 1
argv[2] = 2
argv[3] = 3
argv[4] = 4
```

### Casting
Command-line arguments that are not strings, will need to be cast (converted) to be used in any arithmetic operations. For example, argv[1] value of 1 in the examples above is a string, so must be cased into a integer.

There is a function named `atoi` that is part of the `stdlib.h` library. So the preprocessor statement below is required.

```c
#include <stdlib.h>
```

Using `atoi` to cast the argv element 2 to an integer.

```c
int num_times = atoi(argv[2]);
```

We can now use `num_times` int variable in a for loop.

Here is a simple program, which will take in command-line argv[1] and argv[2]. It prints out argv[1] the number of times defined by argv[2].

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int num_times = atoi(argv[2]);

    for (int i = 0; i < num_times; i++)
        printf("%s\n", argv[1]);

    return 0;
}
```

To execute the program on the terminal.

```bash
$ ./d abc 5
```

**Output**
```bash
aaa
aaa
aaa
aaa
aaa
```

### Validating command-line arguments
With command-line arguments there should be some validation of the given arguments first to avoid runtime errors.

To improve our program we will validate that the number of arguments passed to, is what is expected. If the number of arguments is not as expected, we can return a message, and return an exit status of 1.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc == 3)
    {

        int num_times = atoi(argv[2]);

        for (int i = 0; i < num_times; i++)
            printf("%s\n", argv[1]);
    }
    else 
    {
    printf("Invalid argument count! 2 arguments expected.\n");
    printf("1st argument must be string.\n");
    printf("2nd argument must be number.\n");
    return 1;
    }

    return 0;
}
```