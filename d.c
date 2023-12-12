#include <stdio.h>

int main(void)
{

    float x = 5.2;
    double y = -9.8;

    printf("Enter value for x: ");
    scanf("%f", &x); // Get float from user assign to x
    printf("x: %f\n", x); // print x

    printf("Enter value for y: ");
    scanf("%lf", &y); // Get double from user assign to y
    printf("y: %lf\n", y); // print y

}