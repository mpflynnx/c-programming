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