#include <stdio.h>

int main(void)
{

    char s1[] = "This is my string.";

    if (s1[18] == '\0')
        printf("Thats a null terminator.\n");

    return 0;
}