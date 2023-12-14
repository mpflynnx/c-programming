## While loops

C has three kinds of loops. Loops allow us to repeat execution of blocks of code.

While loop with condition. While loop will execute block inside {} while, condition (i < 5) is true. when (i < 5) is false then while loop will stop executing the code inside {}.

```c
#include <stdio.h>

int main(void)
{

    int i = 0;

    while (i < 5) 
    {
        printf("i: %d\n", i);
        i = i + 1;
    }
    
    return 0;

}
```

Expected output

```bash
i: 0
i: 1
i: 2
i: 3
i: 4
```

### Incrementing a variable

In the example above we used, that shown below to increment the i variable by 1.

```c
i = i + 1;
```

As this is such a common expression in programming, short cut version exists such as:

```c
i += 1; // Add 1 to i
1 += 5; // Add 5 to i
```

```c
i++; // Add 1 to i
```

### Find average of numbers using while loop

Here is a program which will ask the user to enter five numbers then return the total of the five numbers given and the average of the five numbers.

```c
#include <stdio.h>

int main(void)
{

    int i = 0;
    int number = 0;
    int total = 0;

    while (i < 5) 
    {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &number);
        total = total + number;
        i++;
    }

    printf("total: %d\n", total);
    printf("average: %d\n", total/5 );
    
    return 0;

}
```

Expected output:

```bash
Enter Number 1: 9
Enter Number 2: 12
Enter Number 3: 60 
Enter Number 4: 20
Enter Number 5: 45
total: 146
average: 29
```

In the above example we hardcoded a predefined number of times the loop should run of 5. We can also ask the user how many times is needed for the loop to run.

```c
#include <stdio.h>

int main(void)
{

    int i = 0;
    int number = 0;
    int total = 0;
    int total_numbers = 0;

    printf("How many numbers: ");
    scanf("%d", &total_numbers);

    while (i < total_numbers) 
    {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &number);
        total = total + number;
        i++;
    }

    printf("total: %d\n", total);
    printf("average: %d\n", total/total_numbers );
    
    return 0;

}
```

Expected output:

```bash
How many numbers: 10
Enter Number 1: 1
Enter Number 2: 2
Enter Number 3: 3
Enter Number 4: 4
Enter Number 5: 5
Enter Number 6: 6
Enter Number 7: 7
Enter Number 8: 8
Enter Number 9: 9
Enter Number 10: 10
total: 55
average: 5
```

### Indefinite loop using a while loop

A loop than can be run a unknown number of times, can be programmed using a while loop.

In this example the program will continue asking the user for a positive number, until the number given is -1. Upon the number -1 being entered, the program exits the while loop and prints to screen the highest number that the user entered.

```c
#include <stdio.h>

int main(void)
{

    int num = 0; // Initial value of num is 0
    int max = -1; // Initial max number start value, so that num of 0 is greater than max of -1
    
    while ( num != -1 ) // loop while num is not -1
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > max) max = num; // nested structure inside a while loop

    }
    printf("max: %d\n", max);

    return 0;

}
```

Expected output:

```bash
Enter a number: 1
max: 1
Enter a number: 3
max: 3
Enter a number: 2
max: 3
Enter a number: 4
max: 4
Enter a number: 6
max: 6
Enter a number: 5
max: 6
Enter a number: -1
max: 6
max: 6
```

### Infinite loop

An infinite loop is a loop that will never terminate. On some occasions this can be beneficial, but mostly infinite loops should be avoided.

```c
#include <stdio.h>

int main(void)
{

    int i = 10;

    while (i < 20) // i will always be < 20
    {
        printf("i: %d\n", i);
        i--; // decrement i, same as: i = i - 1
    }

    return 0;

}
```

Output:

```bash
i: -151239
i: -151240
i: -151241
i: -151242
i: -151243
i: -151244
i: -151245
```

`i` is being decremented continuously. The loop will never get to `i` being greater than 20.

This program will never end. Press keys, Control + c to force the program to exit.