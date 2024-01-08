#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *fh_write;
    fh_write = fopen("write.txt", "w");
    if (fh_write == NULL)
    {
    printf("Error opening file!\n");
    return 1;
    }
    else 
    {
        fprintf(fh_write, "Hello, world!\n");
        fclose(fh_write);
    }

    return 0;
}

