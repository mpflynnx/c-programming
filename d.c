#include <stdio.h>

int main(void)
{

    int number = 2;

    switch (number) 
    {
        case 0:
            printf("Case 0!\n");
            break;
        case 1:
            printf("Case 1!\n");
            break;
        default:
            printf("Default case!\n");
    }

    return 0;
}