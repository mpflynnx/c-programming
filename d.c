#include <stdio.h>

int main(void)
{

    // inputs to program
    int speed = 0;
    int time = 0;

    // Ask user for value of speed
    printf("Enter value for speed: ");
    // Expects integer %d from input, will assign to speed variable using & operator.
    scanf("%d", &speed);

    // Ask user for value of time
    printf("Enter value for time: ");
    // Expects integer %d from input, will assign to time variable using & operator.
    scanf("%d", &time);

    // processing
    int distance = speed * time;

    // output
    printf("distance: %d\n", distance);

}