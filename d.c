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