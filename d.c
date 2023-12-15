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