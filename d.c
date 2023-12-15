#include <stdio.h>

int main(void)
{

    char s1[20]; // char array length 20

    printf("Enter text (no spaces): ");

    // Read string and stored in s1, no need for & why? See section on pointers.
    scanf("%s", s1); 

    for (int i = 0; i < 20; i++)
        printf("s1[%d] = %c\n", i, s1[i]);

    printf("s1: %s\n", s1);
    
    return 0;
}