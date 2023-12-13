#include <stdio.h>

int main(void)
{

    int i = 0;
    int number = 0;
    int total = 0;

    int total_numbers = 0;

    printf("How many numbers: ");
    scanf("%d", &total_numbers);

    while (i < total_numbers) 
    {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &number);
        total = total + number;
        i++;
    }

    printf("total: %d\n", total);
    printf("average: %d\n", total/total_numbers );
    
    return 0;

}