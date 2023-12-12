#include <stdio.h>

int main(void)
{

    int grade = 0;

    printf("Grade: ");
    scanf("%d", &grade);

    if (grade >= 90) printf("A\n");
    else if (grade >= 80) printf("B\n");
    else printf("Other\n");
    
    return 0;

}