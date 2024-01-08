#include <stdio.h>
#include <stdlib.h>

int x = 10;

void func();

int main(int argc, char *argv[])
{
    int x = 20;
    printf("main x: %d\n", x);
    func();
    return 0;
}

void func()
{
    x++;
    printf("func x: %d\n", x);
}

