## Accepting user inputs with spaces

The `c` programming language is know as a system level language. It is higher than assembly language but lower than Java or Python languages. The `c` programming language is designed to be used for firmware, operating systems and embedded systems, so some things are harder to achieve using it. Accepting user inputs with spaces for example.

In the example program below, `scanf` will accept only a user input string up to the first space.
```c
#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER 100

int main(int argc, char *argv[])
{

    char buffer[LINE_BUFFER];
    printf("Enter: ");
    scanf("%s", buffer);
    printf("Buffer: %s\n", buffer);
    return 0;
}
```

**Output**
```bash
Enter: CapturesTextUpTo FirstSpace                               
Buffer: CapturesTextUpTo
```

As an alternative to using `scanf` we can use `fgets.` Instead of passing in a file name to `fgets`, we pass in keyword `stdin` which is the input from the user on the terminal.

```c
fgets(buffer, 100, stdin);
```
**Output**
```bash
Enter: CapturesTextBeyond FirstSpace
Buffer: CapturesTextBeyond FirstSpace
```