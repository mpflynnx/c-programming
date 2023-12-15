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

In the following program. 
- I create a char array of length 20. 
- I request the user to enter some characters.
- I then store the chars in array s1.
- I then print all the elements of the array s1.

```c
#include <stdio.h>

int main(void)
{

    char s1[20]; // char array length 20

    printf("Enter text (no spaces): ");

    // Read string and store in s1.
    // No need for &s1, why? See section on pointers.
    scanf("%s", s1); 

    for (int i = 0; i < 20; i++)
        printf("s1[%d] = %c\n", i, s1[i]);

    printf("s1: %s\n", s1);
    
    return 0;
}
```

Output:

```bash
Enter text (no spaces): textnospaces
s1[0] = t
s1[1] = e
s1[2] = x
s1[3] = t
s1[4] = n
s1[5] = o
s1[6] = s
s1[7] = p
s1[8] = a
s1[9] = c
s1[10] = e
s1[11] = s
s1[12] = 
s1[13] = 
s1[14] = 
s1[15] = 
s1[16] = 
s1[17] = 
s1[18] = 
s1[19] =
s1: textnospaces
```

Notice that there are empty elements of the array, because the number of characters entered by the user was less than the array length.

What signifies the end of the string is the null terminator not the length of the char array. The null terminator has been placed at element 12, but is not printable so looks empty.

The array was not initialised with all zeros, so there could be junk data displayed when the array elements are printed.

### Counting characters in a string

We can use the null terminator to help search through a string, without needing to know the length of the string.

In the following program. 
- I create a char array of length 20. 
- I request the user to enter some characters.
- I then store the chars in array s1.
- I then check every element in the array for the character 0.
- I exit the while loop when the null terminator is found.

```c
#include <stdio.h>

int main(void)
{

    char s1[20]; // char array length 20

    printf("Enter text (no spaces): ");

    // Read string and store in s1.
    // No need for &s1, why? See section on pointers.
    scanf("%s", s1); 

    int i = 0;

    while (s1[i] != '\0')
    {
        if (s1[i] == '0')
            printf("Found 0 at s1[%d]\n", i);
        i++;
    }

    printf("s1: %s\n", s1);

    return 0;
}
```

Output:

```bash
Enter text (no spaces): 102030405060
Found 0 at s1[1]
Found 0 at s1[3]
Found 0 at s1[5]
Found 0 at s1[7]
Found 0 at s1[9]
Found 0 at s1[11]
s1: 102030405060
```