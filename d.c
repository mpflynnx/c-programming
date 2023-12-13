#include <stdio.h>

int main(void)
{

    int i = 0;

    do 
    {
        printf("Enter number (>0): ");
        scanf("%d" , &i);
        if (i <= 0)
            printf("Number must be >0!\n");
    } while (i <= 0); // while i less than 0, continue loop

    return 0;

}