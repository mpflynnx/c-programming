#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_array(int data[ROWS][COLS]);
void input_array(int data[ROWS][COLS]);

int main(void)
{

    int data[ROWS][COLS] = { 0 };

    input_array(data);

    print_array(data);

    return 0;
}

void print_array(int data[ROWS][COLS])
{
    printf("\nPrinting 2D array....\n");
    for (int i = 0; i < ROWS; i++) // Outer loop for rows
        for (int j = 0; j < COLS; j++) // Inner loop for columns
            printf("data[%d][%d] = %d\n", i, j, data[i][j]);
}

void input_array(int data[ROWS][COLS])
{
    printf("Populate 2D array....\n");
    for (int i = 0; i < ROWS; i++) // Outer loop for rows
        for (int j = 0; j < COLS; j++) // Inner loop for columns
        {
            printf("Enter data[%d][%d] = ", i, j);
            scanf("%d", &data[i][j]);
        }
}