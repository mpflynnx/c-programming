#include <stdio.h>

int main(void)
{

    int height = 0;
    int weight = 0;

    printf("Height: ");
    scanf("%d", &height);

    if (! (height > 150))
        printf("Not good!\n");
    else
     printf("Good!\n");
    
    return 0;

}