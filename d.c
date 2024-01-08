#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER 100

int main(int argc, char *argv[])
{

    char buffer[LINE_BUFFER];
    printf("Enter: ");
    // scanf("%s", buffer); // Stops at first space
    fgets(buffer, 100, stdin);
    printf("Buffer: %s\n", buffer);
    return 0;
}
