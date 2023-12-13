#include <stdio.h>

int main(void)
{

    int num = 0; // Initial value of num is 0
    int max = -1; // Initial max number start value, so that num of 0 is greater than max of -1
    
    while ( num != -1 ) // loop while num is not -1
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > max) max = num; // nested structure inside a while loop
        printf("max: %d\n", max);
    }
    printf("max: %d\n", max);

    return 0;

}