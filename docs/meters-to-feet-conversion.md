## Meters to Feet conversion program

Now we know about `While loops` and `For loops` we can start to create useful programs.

We can use the `While loops` to request and validate inputs from the user.
We can use `For loops` to work on the inputs provided.

Here is a program that will convert Meters to Feet and display a conversion table to the user.

The user is requested to enter:

- A start number.
- A step number.
- A stop number.

```c
#include <stdio.h>

int main(void)
{

    double start = 0, step = 0, stop = 0;

    do {
        printf("Enter start (m): ");
        scanf("%lf", &start);
        if (start < 0) printf("Must be >=0!\n");
    }while (start < 0);

    do {
        printf("Enter step (m): ");
        scanf("%lf", &step);
        if (step <= 0) printf("Must be >0!\n");
    }while (step <= 0);

    do {
        printf("Enter stop (m): ");
        scanf("%lf", &stop);
        if (stop < 0) printf("Must be >=0!\n");
    }while (stop < 0);

    printf("\nMeters     Feet\n");
    printf("*******************\n");
    for (double conv = start; conv <= stop; conv += step)
    {
        printf("%f %f\n", conv, conv * 3.28084);
    }
}
```

### Explanation

Here, I initialise three double variables to 0;
```c
    double start = 0, step = 0, stop = 0;
```

Here, I use a while loop to validate the users `start` input. The number provided must be positive.

```c
    do {
        printf("Enter start (m): ");
        scanf("%lf", &start);
        if (start < 0) printf("Must be >=0!\n");
    }while (start < 0);
```

Here, I use a while loop to validate the users `step` input. The number provided must be positive and greater than 0.

```c
    do {
        printf("Enter step (m): ");
        scanf("%lf", &step);
        if (step <= 0) printf("Must be >0!\n");
    }while (step <= 0);
```

Here, I use a while loop to validate the users `stop` input. The number provided must be positive.

```c
    do {
        printf("Enter stop (m): ");
        scanf("%lf", &stop);
        if (stop < 0) printf("Must be >=0!\n");
    }while (stop < 0);
```

I then use a `For loop` to perform the conversion and display to the user a conversion table.

```c
    for (double conv = initial; conv <= stop; conv += step)
    {
        printf("%f %f\n", conv, conv * 3.28084);
    }
```

Output

```bash
Enter start (m): 1
Enter step (m): 0.5
Enter stop (m): 5

Meters     Feet
*******************
1.000000 3.280840
1.500000 4.921260
2.000000 6.561680
2.500000 8.202100
3.000000 9.842520
3.500000 11.482940
4.000000 13.123360
4.500000 14.763780
5.000000 16.404200
```