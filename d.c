#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *fh_read;
    fh_read = fopen("write.txt", "r");
    if (fh_read == NULL)
    {
    printf("Error opening file!\n");
    return 1;
    }
    else 
    {
        char buffer[100];
        int data[10];
        int i = 0;
        printf("...Printing file contents...\n");
        while (fgets( buffer, 100, fh_read) != NULL)
        {
            printf("%s", buffer);
            data[i] = atoi(buffer);
            i++;
        }
        fclose(fh_read);
        int num_lines = i;
        int total = 0;
      
        printf("\n...Printing data array...\n");
        for (int j = 0; j < num_lines; j++)
        {
            printf("data[%d]=%d\n", j, data[j]);
            total += data[j];
        }
        printf("average: %d\n", total / num_lines);    
    }

    return 0;
}

