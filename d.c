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

// compile in terminal, make sure folder same as `d.c` file
// $ gcc -o d d.c

// execute in terminal
// $ ./d