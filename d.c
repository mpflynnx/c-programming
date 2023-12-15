#include <stdio.h>

int main(void)
{

    char s1[] = "This is my string.";

    for (int i = 0; i < 18; i++)
        printf("s1[%d] = %c\n", i, s1[i]);

    if (s1[18] == '\0')
        printf("Thats a null terminator.\n");

    return 0;
}