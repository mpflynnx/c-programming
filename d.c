#include <stdio.h>

int main(void)
{

    int grade = 0;

    printf("Grade: ");
    scanf("%d", &grade);

    if (grade >= 50)
    {
        // if true execute this block
        printf("Pass\n");
        printf("Congrats!\n");
    }

    // if false do not execute block
    printf("If statement done.\n");

    return 0;

}