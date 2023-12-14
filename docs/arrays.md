## Arrays

An `Array` is a data structure. It allows for a collection of related data.

For example, we may have a collection of student grades.

### Creating an Array
To create an array of integers we use:

```c
int grade[5];
```

This array has 5 elements (locations) for us to store integers, they are indexed 0, 1, 2, 3, 4.
To store an integer at element 1 which is index 0, we use:

```c
grade[0] = 92;
```

To store an integer at element 2 which is index 1, we use:
```c
grade[1] = 85;
```

To store an integer at element 3 which is index 2, we use:
```c
grade[2] = 72;
```
### Accessing an Array index
To access the contents of `grade` array index 1 we use:

```c
printf("grade[1] = %d\n", grade[1]);
```

Output:
```bash
grade[1] = 85
```

### Using a for loop with Arrays
To print all the contents of the array we can use a `For loop`.

```c
    for (int i = 0; i < 5; i++)
        printf("grade[%d] = %d\n", i, grade[i]);
```

Output:
```bash
grade[0] = 92
grade[1] = 85
grade[2] = 72
grade[3] = 73
grade[4] = 95
```

### Finding the average of student grades
We can use a `For loop` with an `Array` to calculate the average grade across all students.

```c
    int total = 0;
    for (int i = 0; i < 5; i++)
        total += grade[i]; 
    printf("average: %d\n", total / 5);
```

Each `Array` elements value is retrieved and added to the `total` variable. We then divide `total` by the number of elements in the `Array` to get the average grade.

Output:
```bash
average: 83
```

`For loops` used with `Arrays` allow use to scale our programs without writing more code. 

### Updating an Array element

We can update an `Array` element, much like we do with variables.

In the example below, element 2 is being updated.

```c
grade[2] = grade[2] + 5;
```

Equivalent to:

```c
grade[2] = 72 + 5; // 77
```

### Initialising Arrays

We have seen the method shown below:

```c
    grade[0] = 92;
    grade[1] = 85;
    grade[2] = 72;
    grade[3] = 73;
    grade[4] = 95;
```
The same thing can be achieved using just one line as shown below:

```c
int grade[] = {92, 85, 72, 73, 95};
```

With the above method we do not need to explicitly state the array size, the C compiler can determine it's size from the list of numbers given in {}.

### Common errors using Arrays

It can sometimes be easy to try to access an index in an `Array` that is not available. 

Here, we try to assign to index 5 the value 100. We have an `Array` size of 5 but our last index is 4. Therefore index 5 doesn't exist.

```c
grade[5] = 100;
```

The C compiler will flag a warning such as:

```bash
...
warning: array index 5 is past the end of the array
...
```

If you ignore the warning the program will compile. C allows this to happen, but it is not safe, as you may be accessing computer memory that is used for something else.