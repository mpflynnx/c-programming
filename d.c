#include <stdio.h>

int main(void)
{

    int grade = 0;

    printf("Grade: ");
    scanf("%d", &grade);

    if (grade >= 50)
        printf("Pass\n");

    return 0;

}