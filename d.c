#include <stdio.h>

int main(void)
{

    int height = 0;
    int weight = 0;

    printf("Height: ");
    scanf("%d", &height);

    printf("Weight: ");
    scanf("%d", &weight);

    if (height > 150 || weight > 50)
        printf("Good!\n");
    else
     printf("Not good!\n");
    
    return 0;

}