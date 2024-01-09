#include <stdio.h>

int factorial(int n);

int main(void)
{

    int n = 0;
    int fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    // while (n >= 1)
    // {
    //     fact = n * fact;
    //     n--;
    // }

    fact = factorial(n);

    printf("Factorial is: %d\n", fact);

    return 0;
}

int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n - 1);
}