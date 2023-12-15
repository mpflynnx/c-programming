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
The `C` compiler automatically creates a char array of length 19 this is because a null type terminator is added by default to the end which is index number 18.

### Printing a char array

In this example the char array is printed. Note: The null type terminator is a non printable character so cannot be printed.

```c
for (int i = 0; i < 18; i++)
    printf("s1[%d] = %c\n", i, s1[i]);
```

```bash
s1[0] = T
s1[1] = h
s1[2] = i
s1[3] = s
s1[4] =  
s1[5] = i
s1[6] = s
s1[7] =  
s1[8] = m
s1[9] = y
s1[10] =  
s1[11] = s
s1[12] = t
s1[13] = r
s1[14] = i
s1[15] = n
s1[16] = g
s1[17] = .
```

You can check for equality of the null type terminator with:

```c
if (s1[18] == '\0')
    printf("Thats a null terminator.\n");

```

Note: `\0` is in fact stored as one character, so can be used inside single quotes.

### Finding the length of a string

