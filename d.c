#include <stdio.h>

long int factorial(int n);

int main(void)
{

    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %ld\n", n, factorial(n));

    return 0;
}

long int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n-1);
}