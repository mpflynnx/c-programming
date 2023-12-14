#include <stdio.h>

int main(void)
{

    double start = 0, step = 0, stop = 0;

    do {
        printf("Enter start (m): ");
        scanf("%lf", &start);
        if (start < 0) printf("Must be >=0!\n");
    }while (start < 0);

    do {
        printf("Enter step (m): ");
        scanf("%lf", &step);
        if (step <= 0) printf("Must be >0!\n");
    }while (step <= 0);

    do {
        printf("Enter stop (m): ");
        scanf("%lf", &stop);
        if (stop < 0) printf("Must be >=0!\n");
    }while (stop < 0);

    printf("\nMeters     Feet\n");
    printf("*******************\n");
    for (double conv = start; conv <= stop; conv += step)
    {
        printf("%f %f\n", conv, conv * 3.28084);
    }
}