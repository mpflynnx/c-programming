#include <stdio.h>

void add_one(int array[], int length);

int main(void)
{

    int a = 5;
    int *p;
    p = &a;
    printf("p: %p\n", p);
    printf("&a: %p\n", &a);

    int b = 10;
    printf("&b: %p\n", &b);

    a = a + *p;
    printf("%d\n", *p);

    p = &b;
    printf("p: %p\n", p);

    *p = *p + 1; // b = b + 1

    printf("b: %d\n", b);

    return 0;
}
