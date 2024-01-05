## typedef and struct

`typedef` and `struct` allow us to define new types. 

### typedef

**typedef example usage**

```c
typedef int inches;
```

The above creates a new type `inches` which is a pseudonym for `int`. Using typedef helps improve the readability of the code.

With the code below, the reader is unsure what the relationship is with `person1` and the int value `181`.
```c
int person1 = 181;
```

By using a typedef, the code has now created a relationship with `person1` and the int value `181`. People are usually measured in inches so this variable is for the height of a `person1`.

```c
inches person1 = 181;
```

As `inches` is the same type as `int`, we can use `inches` the same way we use `int` types.

```c
printf("person1: %d\n", person1);
```
  
`typedef` is often used along with `struct`. 

### struct

`struct` allows related information to be grouped together in a record. We have seen arrays only allow the same type of information to be stored together, such as integers. A `struct` allows us to store different types of information. For example `person1` may have a first name (char), last name(char), age(integer), height(float) etc, by grouping them together, this is more readable.

**struct example usage**

To define a point in a 2 dimensional space, we have x and y co-ordinates. Use `struct` to create a new type Point with two members x and y for the co-ordinates. 

**Notice** the uppercase first letter for the struct name, i.e Point not point.

```c
struct Point
{
    int x;
    int y;
};
```

To create a new `Point` struct named `p1`.

```c
struct Point p1;
```

We can initialise the values for the x and y members using dot notation.

```c
p1.x = 5;
p1.y = 3;
```

Because `x` and `y` members are integers we can use the `%d` placeholder with `printf`.

```c
printf("(%d, %d)\n", p1.x, p1.y);
```

We can create as many struct Points as required.

```c
struct Point p2;
```

### Initialising struct members

Similar to how values are assigned in arrays we can use:

```c
struct Point p3 = {1, 2}; // {x = 1, y = 2}
```

We can initialise out of order using: -

```c
struct Point p4 = 
{
    .y = 7,
    .x = 6
};
```

### Using typedef with struct

We have seen that when we initialise a struct, we always have to type `struct` then the struct name. We can use `typedef` to save us typing `struct` every time we initialise a struct.

Using `typedef` to create a new `struct` type named `Point`.
```c
typedef struct
{
    int x;
    int y;
} Point;
```

The struct can then be initialised without the need for the struct keyword.

```c
Point p4 = {1, 2}; // {x = 1, y = 2}
```

I mentioned that a `typedef` can contain a mixture of different types. In the example below a struct type of `Student` has a first name, last name and age. 

```c
typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
} Student;
```

I can create a new `Student` type and can initialise the members as shown.

```c
Student s1;
s1.age = 20;
strcpy(s1.first_name, "Devon");
strcpy(s1.last_name, "Smith");
```

[`strcpy`](https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm) is a function from the string.h library.

### Passing a struct to a function

We can pass a struct `Student` to a function, which will handle the printing of `Student` member values.

We must declare the struct at the top of the file, before passing it to the function.

```c
typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
} Student;

void print_student(Student s);
```

we can now call from the main function the `print_student` function, passing in struct `Student` `s1`.

```c
int main(void)
{

    Student s1;
    s1.age = 20;
    strcpy(s1.first_name, "Devon");
    strcpy(s1.last_name, "Smith");

    print_student(s1); // Call function
    
    return 0;
}

void print_student(Student s)
{
    printf("%s %s\n", s.first_name, s.last_name);
    printf("Age: %d\n", s.age);
}
```

**Output:-**
```bash
Devon Smith
Age: 20
```

### Problems with passing structs
Structs are pass by value, passing struct to fucntions work like int types. The passed struct cannot be updated in the called function, as a copy of the struct is made when the function is called. The function uses the copy. This means that the struct is duplicated in memory. This can be problematic if the struct contains many large arrays for example. This is why programmers mostly use dynamic memory allocation and pass by reference with structs.

### Using dynamic memory allocation with structs

Firstly we create a new pointer of type Student.
```c
Student *s1; //pointer to a Student type
```

Then we create a block of memory on the heap, big enough to store 1 Student type.

```c
s1 = calloc(1, sizeof(Student));
```

We can initialise a struct member in two ways.

```c
(*s1).age = 20;
```
Or the cleaner preferred method: 

```c
s1->age = 20;
```

How the `->` works is: At the block of memory pointed to by `s1`, get the `age` member variable in that block of memory and set it to `20`.

###  Struct pass by reference
We can use a function to accept a pointer to a `Student` struct as an argument and use pass by reference with structs. We can then update the struct member variable from the called function.

In this example function `age_student` accepts a Student pointer as an argument and will then increment struct member `age` by 1.
```c
void age_student(Student *s)
{
    s->age += 1;
}
```

To call the function from the main function use:

```c
age_student(s1); // s1 is pointer
```
**Completed program**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
} Student;

void age_student(Student *s);

int main(void)
{
    Student *s1; //pointer to a Student type

    s1 = calloc(1, sizeof(Student));

    printf("Age: %d\n", (*s1).age );

    age_student(s1);

    printf("Age: %d\n", (*s1).age );

    free(s1);

    return 0;
}

void age_student(Student *s)
{
    s->age += 1;
}
```

**Output**

```bash
Age: 0
Age: 1
```

### Struct pointer members

If the struct does not contain pointer members, we can duplicate structs easily without problems. 

```c
typedef struct
{
    int data;
} Info;
```

Create and initialise member `data`.

```c
Info a;
a.data = 7;
```

Create a duplicate struct as shown:

```c
Info b; // Create new struct b
b = a;  //  assign b struct a struct
```

`a.data` gets duplicated in memory as `b.data`. Changes to `a.data` will not effect `b.data`.

```c
printf("b.data: %d\n", b.data); // Output 7, same as a.data
```
We can give pointers as structs members. This pointer may be a pointer on some dynamically allocated memory on the heap.

```c
typedef struct
{
    int data;
    int *array; // pointer
} Info;
```

When we assign `a` struct to `b` struct the pointer value gets copied, the data does not get duplicated. Therefore the values of `b.array` is the actual `a.array` not a duplicate. Changes to the `a.array` will change the `b.array` as they are pointing to the same memory location.

Create and initialise member `data` and member `array`.

```c
Info a;
a.data = 7;
a.array = malloc(sizeof(int) * 5);

// assign values to a.array
for (int i = 0; i < 5; i++)
    a.array[i] = i + 1;
```

Create a duplicate struct and print the values of `b.data` and `b.array`.

```c
Info b = a;

// print b.data
printf("b.data: %d\n", b.data); // 7

// print b.array
for (int i = 0; i < 5; i++)
    printf("b.array[%d] = %d\n", i, b.array[i]);
```

**Output**
```bash
b.data: 7
b.array[0] = 1
b.array[1] = 2
b.array[2] = 3
b.array[3] = 4
b.array[4] = 5
```

Update `a.data` and `a.array` as shown.

```c
a.data = 8; // Update a.data

// assign new values to a.array
for (int i = 0; i < 5; i++)
    a.array[i] = i + 2;
```

Print `b.data` and `b.array`.

```c
// print b.data
printf("b.data: %d\n", b.data);

// print b.array
for (int i = 0; i < 5; i++)
    printf("b.array[%d] = %d\n", i, b.array[i]);
```

**Output**
```bash
b.data: 7
b.array[0] = 2
b.array[1] = 3
b.array[2] = 4
b.array[3] = 5
b.array[4] = 6
```

`b.data` remains 7, but `b.array` has changed because `a.array` was changed. `b.array` and `a.array` point to the same memory locations.

To confirm, print out the values of `a.array` and `b.array`.

```c
printf("a.array: %p\n", a.array);
printf("b.array: %p\n", b.array);
```

**Output**
```bash
a.array: 0x55a2bf79a2a0
b.array: 0x55a2bf79a2a0
```

Confirmed `b.array` and `a.array` point to the same memory locations.
