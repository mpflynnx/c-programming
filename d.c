#include <stdio.h>

int main(void)
{

    int i = 0;

    do 
    {
        printf("i: %d\n", i);
        i++;
    } while (i < 5); // notice ; after condition, for do while loops

    return 0;

}