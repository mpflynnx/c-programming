## 2D arrays

A 2D array consists of rows and columns. Create and initialise new 2D array named `data` as shown.

```c
int data[2][3] = { {1,2,3},
                   {4,5,6} };
```

The first [] after the name `data` is the number of rows, i.e 2. The second [] is the number of columns, i.e 3.

To retrieve the values of the first row and first column.

```c
printf("data[1][1] = %d\n", data[1][1]);
```

**Output**
```bash
data[1][1] = 5
```

Alternatively, we could create and initialise the array as shown below and obtain the same results.

```c
int data[2][3] = { 1,2,3,4,5,6 };
```

This isn't as readable, but can be used.

### Nested loops
To retrieve the values of a 2D array we can use a nested loop.

```c
for (int i = 0; i < 2; i++) // Outer loop for rows
    for (int j = 0; j < 3; j++) // Inner loop for columns
        printf("data[%d][%d] = %d\n", i, j, data[i][j]);
```

**Output**
```bash
data[0][0] = 1
data[0][1] = 2
data[0][2] = 3
data[1][0] = 4
data[1][1] = 5
data[1][2] = 6
```

### Using constants
We have seen that in the nested for loop, we had to manually assign the number of rows i.e `i < 2` and columns `j < 3` to match that of the `data` array.

To make the program more readable and maintainable, we can define a constant for the array rows and columns. Then use the constant name, everywhere it is required in the program, even in functions.

At the top of the file below any `#include` statements, use the following preprocessor statements.

```c
#define ROWS 3 // Number of rows 3
#define COLS 3 // Number of columns 3
```

We can then use the ROWS and COLS constant names in the array initialisation and the nested for loop as shown.

```c
int data[ROWS][COLS] = { 0 }; // Initialise all 2D array elements to zero


for (int i = 0; i < ROWS; i++) // Outer loop for rows
    for (int j = 0; j < COLS; j++) // Inner loop for columns
        printf("data[%d][%d] = %d\n", i, j, data[i][j]);
```

**Output**
```bash
data[0][0] = 1
data[0][1] = 2
data[0][2] = 3
data[1][0] = 4
data[1][1] = 5
data[1][2] = 6
data[2][0] = 7
data[2][1] = 8
data[2][2] = 9
```

### Populating a 2D array using scanf

We can use a nested for loop to request values for the 2D array from the user.

```c
printf("Populate 2D array....\n");
for (int i = 0; i < ROWS; i++) // Outer loop for rows
    for (int j = 0; j < COLS; j++) // Inner loop for columns
    {
        printf("data[%d][%d] = ", i, j);
        scanf("%d", &data[i][j]);
    }
```

**Output**

```bash
Populate 2D array....
Enter data[0][0] = 1
Enter data[0][1] = 2
Enter data[0][2] = 3
Enter data[1][0] = 4
Enter data[1][1] = 5
Enter data[1][2] = 6
Enter data[2][0] = 7
Enter data[2][1] = 8
Enter data[2][2] = 9
```

### 2D arrays and functions

We can pass 2D arrays to functions, and use the constants ROWS and COLS. Here is a function to print the contents of a 2D array.

```c
...

void print_array(int data[ROWS][COLS]);

int main(void)
{
    ...
    print_array(data);
    ...
}

void print_array(int data[ROWS][COLS])
{
    printf("\nPrinting 2D array....\n");
    for (int i = 0; i < ROWS; i++) // Outer loop for rows
        for (int j = 0; j < COLS; j++) // Inner loop for columns
            printf("data[%d][%d] = %d\n", i, j, data[i][j]);
}
```

**Output**
```bash
Populate 2D array....
Enter data[0][0] = 1
Enter data[0][1] = 2
Enter data[0][2] = 3
Enter data[1][0] = 4
Enter data[1][1] = 5
Enter data[1][2] = 6
Enter data[2][0] = 7
Enter data[2][1] = 8
Enter data[2][2] = 9

Printing 2D array....
data[0][0] = 1
data[0][1] = 2
data[0][2] = 3
data[1][0] = 4
data[1][1] = 5
data[1][2] = 6
data[2][0] = 7
data[2][1] = 8
data[2][2] = 9
```

When passing to a function a 2D array we must specify the number rows and columns or there will be a compilation error.

We could omit the number of rows passed and the compiler would accept this, as shown.

```c
void print_array(int data[][COLS])
{

    ...
}
```
Usually both values are known and should be passed to the function.

### 2D array pass by reference

As with one dimensional arrays we pass by reference, as arrays are really pointers. Therefore functions can update the array in place from the calling function.

Here is a function to populate the contents of a 2D array.
```c
...

void input_array(int data[ROWS][COLS]);

int main(void)
{
    ...
    input_array(data);
    ...
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
```
