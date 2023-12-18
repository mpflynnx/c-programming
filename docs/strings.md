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

Note: Problems with this program will occur if the length of the string entered by the user is greater than the length of the array.

For example:

```bash
Enter text (no spaces): 012345678901234567890123456789
Found 0 at s1[0]
Found 0 at s1[10]
Found 0 at s1[20]
s1: 012345678901234567890123456789
*** stack smashing detected ***: terminated
Aborted
```

Here the null terminator is being placed somewhere outside the array, so the program will never find it.

As working with strings is so common in all programming languages, libraries exist to help. 

### string.h library

`string.h` provides a number of functions to help work with strings.

To use the `string.h` library, add the include statement.

```c
#include <string.h>
```

### Finding the length of a string using strlen

A function included in library `string.h` is called `strlen`. This function will return the length of a string. It does not use the null terminator in it's algorithm.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{

    char s1[] = "This is the my string.";

    int length = strlen(s1);

    printf("length: %d\n", length);

    return 0;
}
```
Output:
```bash
length: 22
```

### Counting characters in a string using strlen

We can use the `strlen` function to help search through a string.

In the following program. 
- I create a char array with some characters. 
- I then check every element in the array for the character 0.
- I exit the for loop when the length is reached.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{

    char s1[] = "0123456789012345678901234567890";

    int length = strlen(s1);

    int num_is = 0;

    for (int i = 0; i < length; i++)
        if (s1[i] == '0') num_is++;

    printf("length: %d\n", length);
    printf("Number of 0 is: %d\n", num_is);

    return 0;
}
```

Output:

```bash
length: 31
Number of 0 is: 4
```

### String concatenation using strcat

[`strcat`](https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm) Appends the string pointed to, by source to the end of the string pointed to by destination.

```c
strcat(dest, src);
```

In the following program. 
- I create a char array `s1` of length 50 which will contain a sentence.
- I create a char array `s2` which will contain a sentence. 
- I then use the `string.h` function `strcat` to concatenate `s2` into `s1`
- I the print the new value of `s1`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{

    char s1[50] = "The destination sentence. ";
    char s2[] = "The source sentence.";

    strcat(s1, s2);

    printf("s1: %s\n", s1);

    return 0;
}
```

Output:
```
s1: The destination sentence. The source sentence.
```

Note: The destination string char array `s1` must be large enough to store the source string char array `s2`.

### Checking for string equality using strcmp

[`strcmp`](https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm) Compares the string pointed to, by str1 to the string pointed to by str2.

```c
strcmp(str1, str2);
```

This function return values that are as follows:-

- if Return value < 0 then it indicates str1 is less than str2.

- if Return value > 0 then it indicates str2 is less than str1.

- if Return value = 0 then it indicates str1 is equal to str2.

In the following program. 
- I create a char array `s1`  which will contain a sentence.
- I create a char array `s2` which will contain the same sentence as `s1`. 
- I then use the `string.h` function `strcmp` to compare `s1` to `s2`
- If `0` is returned from the function then print `s1 and s2 are equal.`
- If `0` is not returned from the function then print `s1 and s2 are not equal.`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{

    char s1[] = "This is a string.";
    char s2[] = "This is a string.";

    if (strcmp(s1, s2) == 0)
        printf("s1 and s2 are equal.\n");
    else
        printf("s1 and s2 are not equal.\n");

    return 0;
}
```

### ctype.h library

`ctype.h` Provides several functions that are useful for testing and mapping characters.

To use the `ctype.h` library, add the include statement.

```c
#include <ctype.h>
```

All the functions return non-zero (true) if the argument c satisfies the condition described, and zero(false) if not.

### Finding the uppercase and lowercase letters in a string

To determine if a string contains upper or lowercase letters the following functions are available from the `ctype.h` library.

- `isupper` function checks whether the passed character is an uppercase letter.

- `islower` function checks whether the passed character is lowercase letter.

In the following program. 
- I create a char array `s`  which will contains a sentence of upper and lowercase letters.
- I the iterate through each element in the array.
- I print out each element.
- If the `isupper` function returns true, then print "upper".
- else if the `islower` function returns true, then print "lower".
- Print nothing if the element is not a letter.

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    char s[] = "ThIs Is tHe Way.";

    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        printf("%c ", s[i]);
        if (isupper(s[i]))
            printf("upper\n");
        else if (islower(s[i]))
            printf("lower\n");
        else printf("\n");
    }

    return 0;
}
```

Output:

```bash
T upper
h lower
I upper
s lower
  
I upper
s lower
  
t lower
H upper
e lower
  
W upper
a lower
y lower
. 
```

### Convert uppercase letters to lowercase

To change the case of a letter the following functions are available from the `ctype.h` library.

- `tolower` function converts a given letter to lowercase.

This function returns lowercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

- `toupper` function  converts lowercase letter to uppercase.

This function returns uppercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

In the following program. I will convert lowercase letters in a string to uppercase letters.

- I create a char array `s`  which will contains a sentence of upper and lowercase letters.
- I print the char array.
- I the iterate through each element in the array.
- If the `isupper` function returns true, I use `tolower` to convert the letter in the array to lowercase.
- else if the `islower` function returns true, I use `toupper` to convert the letter in the array to uppercase.
- I print the updated char array.

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    char s[] = "ThIs Is tHe Way.";

    printf("s: %s\n", s);


    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (isupper(s[i])) 
            s[i] = tolower(s[i]);
        else if (islower(s[i]))
            s[i] = toupper(s[i]);
    }

    printf("s: %s\n", s);

    return 0;
}
```

Output:

```bash
s: ThIs Is tHe Way.
s: tHiS iS ThE wAY.
```