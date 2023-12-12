#include <stdio.h>

int main(void)
{

    double x =5.2, y = 2.5;

    double multiple = x * y;
    double addition = x + y;
    double division = x / y;
    double subtraction = x - y;

    printf("mult: %f\n", multiple);
    printf("add: %f\n", addition);
    printf("div: %f\n", division);
    printf("sub: %f\n", subtraction);    

    return 0;

}