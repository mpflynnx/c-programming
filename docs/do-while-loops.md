## Do while loops

Do while loops are used to guarantee to run the loop body at least once. With the while loop there is no guarantee the loop body will run.

### Simple do while loop example

In this example `i` is assigned the number 25. The while loop will only execute, if `i` is less than 5. Using the do while loop, means that the value of `i` will be always be printed and the loop terminates because 25 is not less than 5.

```c
#include <stdio.h>

int main(void)
{

    int i = 25;

    do 
    {
        printf("i: %d\n", i);
        i++;
    } while (i < 5); // ; after condition, for do while loops

    return 0;

}
```

Output:

```bash
i: 25
```

### Do while loop used to validate user input

Do while loops are useful when needing to validate a user input. Only when the correct value is entered should the program proceed.

In this example the user is requested to enter a number greater than 0. If a negative number or zero is entered the user is prompted again. The program only exits the loop when a number greater than 0 is entered.

```c
#include <stdio.h>

int main(void)
{

    int i = 0;

    do 
    {
        printf("Enter number (>0): ");
        scanf("%d" , &i);
    } while (i <= 0); // while i less than 0, continue loop

    return 0;
```

Output:

```bash
Enter number (>0): -12
Number must be >0!
Enter number (>0): 0
Number must be >0!
Enter number (>0): -12312
Number must be >0!
Enter number (>0): 2
```