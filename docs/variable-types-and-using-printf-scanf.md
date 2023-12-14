## Variable types and using printf scanf

### double and float variables

`float` is short hand for floating point value, allows us to store real numbers. That is numbers with decimal places. 0 is also a `float`.

```c
float x = 5.2;
```

`double` is very similar to a float.

```c
double y = -9.8;
```

`double` can store numbers with a higher level of precision, i,e more accuracy. `double` has a greater range, more decimal places. Better for high accuracy calculations, but uses more computer memory.

Using the `scanf` function with floats. Placeholder for `float` is `%f`. 

```c
printf("x: ");
scanf("%f, &x); // store float in variable x
```


Using the `printf` function with floats. Placeholder for `float` is `%f`. 

```c
printf("x: %f\n", x);
```

```c
#include <stdio.h>

int main(void)
{

    float x = 5.2;
    double y = -9.8;

    printf("Enter value for x: ");
    scanf("%f", &x); // Get float from user assign to x
    printf("x: %f\n", x); // print x

}
```
Compile file `d.c` to create new file `d`

Open terminal and type:
```bash
$ gcc -o d d.c
```

Execute file `d`.

```bash
$ ./d
```

Expected output

```bash
$ ./d
Enter value for x: 5.2
x: 5.200000
```

Notice the output `5.200000` we can use modifiers to change the appearance.

`float` does not store the exact number given. See below:

```bash
$ ./d
Enter value for x: -52.245
x: -52.244999
```

This is due to the way the computer stores the number in memory. It cannot store exactly the 52.245 but it is very very close.

To use `double` with `scanf` we use the placeholder `%lf` large float.

To use `double` with `printf` we can also user `%lf` but `%f` will also work.

```c
    printf("Enter value for y: ");
    scanf("%lf", &y); // Get double from user assign to y
    printf("y: %lf\n", y); // print y

}
```

Recompile and run program.

Expected output

```bash
$ ./d
Enter value for x: 20.2
x: 20.200001
Enter value for y: -10.88
y: -10.880000
```

### char variable

`char` variable. For storing characters, must be assigned in single quotes. char are fundamentally integer values. Using the ASCII code which is a integer. For example the ASCII code for `d` is 100.

```c
char c = 'd';
```

### printf and scanf with char variables

`%c` is the placeholder for using char variables.

```c
    printf("c: ");
    scanf("%c", &c);
    printf("c: %c\n", c);
}
```

Can also use `%d` which in normally for integers. To print the ASCII integer value of the character `d` i.e 100.

```c
    printf("c: %d\n", c);
```

Compile and run program.

Expected output.

```bash
$ ./d
c: d
c: d
c: 100
```