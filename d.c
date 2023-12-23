#include <stdio.h>

int find_max(int a, int b);

int main(void)
{
    int result = find_max(10, 12) + 10;
    printf("result: %d\n", result);
    return 0;
}

int find_max(int a, int b)
{
    if (a > b) return a;
    else return b;
}