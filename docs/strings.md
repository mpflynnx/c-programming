## Strings

Strings in C are `char` type arrays that end with a null type terminator `\0`. This terminator signifies the end of the string.

```c
char mydata[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

### Printing Strings
The placeholder `%c` is used to print a `char`.

```c
printf("mydata[2] = %c\n", mydata[2]);
```

Output:
```bash
mydata[2] = l
```

The placeholder `%s` is used to print the full `char` type array.

```c
printf("\n%s\n", mydata);
```

Output:
```bash
Hello
```

### Initialise char array alternative

A short cut way to initialise a `char` array in `C` is to use the code below:

```c
char s1[] = "This is my string.";
```

`C` creates a char array of length 19, as a null type terminator is added by default to the end.
Note the null type terminator is a non printable character so cannot be printed.

You can check for equality of the null type terminator with:

```c
if (s1[18] == '\0')
    printf("Thats a null terminator.\n");

```

Note: `\0` is in fact one character, so can be used inside single quotes.

### Find length of a string

