#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc == 3)
    {

        int num_times = atoi(argv[2]);

        for (int i = 0; i < num_times; i++)
            printf("%s\n", argv[1]);
    }
    else 
    {
    printf("Invalid argument count! 2 arguments expected.\n");
    printf("1st argument must be string.\n");
    printf("2nd argument must be number.\n");
    return 1;
    }

    return 0;
}

