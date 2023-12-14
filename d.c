#include <stdio.h>

int main(void)
{

    int grade[] = {92, 85, 72, 73, 95};

    // Print all student grades.
    for (int i = 0; i < 5; i++)
        printf("grade[%d] = %d\n", i, grade[i]);

    // Calculate average grade
    int total = 0;
    for (int i = 0; i < 5; i++)
        total += grade[i];
    printf("average: %d\n", total / 5);

    return 0;
}