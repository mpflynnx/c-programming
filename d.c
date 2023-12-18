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