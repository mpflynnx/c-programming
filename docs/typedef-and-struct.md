## Typedefs and structs

## Table of Contents
- [Typedefs](#typedefs)
    - [Using typedefs to make complex types easier to read](#using-typedefs-to-make-complex-types-easier-to-read)
    - [Using typedefs to document the meaning of a value](#using-typedefs-to-document-the-meaning-of-a-value)
    - [Using typedefs for platform independent coding](#using-typedefs-for-platform-independent-coding)
    - [Using typedefs for easier code maintenance](#using-typedefs-for-easier-code-maintenance)
    - [typedef verses #define](#typedef-verses-define)
    - [Typedef best practices](#typedef-best-practices)
- [struct](/docs/typedef-and-struct.md#struct)
    - [Initialising struct members](#initialising-struct-members)
    - [Using typedef with struct](#using-typedef-with-struct)
    - [Passing a struct to a function](#passing-a-struct-to-a-function)
    - [Problems with passing structs](#problems-with-passing-structs)
    - [Using dynamic memory allocation with structs](#using-dynamic-memory-allocation-with-structs)
    - [Struct pass by reference](#struct-pass-by-reference)
    - [Structs pointers members](#struct-pointer-members)

- [External References](#external-references)


### Typedefs

A typedef (which is short for “type definition”) is a way of creating an alias for a type. To create a typedef alias, we use the `typedef` keyword.

The name `typedef` suggests that a new type is being defined, but that’s not true. A typedef is just an alias.

**typedef example usage**

Declare `typedef` near the top of file below any preprocessor statements.
```c
typedef type alias-name;
```
It’s easy to forget whether the name of the typedef or the name of the type to alias comes first.

```c
typedef int inches; // aliased type name first (i.e int)
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
printf("person1: %d\n", person1); // %d used for inches and int
```
### Using typedefs to make complex types easier to read

`typedef` allows you to take complex types and give them a simpler name, which makes your code easier to read and saves typing.

```c
#include <stdio.h>

typedef int* int_pointer; // alias for a int pointer

int main() {
    // declare multiple pointers on one line using typedef.
    int_pointer p, q; // both p and q become pointers
    
    int *r, s; // only r is a pointer s is a int
..
```

Syntax for a `typedef` can get ugly with more complex types. For example, here is a hard-to-read typedef.

```c
typedef int (*FcnType)(double, char); // FcnType hard to find
```

`typedef` allow you to take complex types and give them a simpler name, which makes your code easier to read and saves typing.

### Using typedefs to document the meaning of a value

Take this function prototype. 
```c
int printData();
```
The return type of `int` does not tell us much. If we’re lucky, documentation for the function exists somewhere that we can reference.

Now let’s do an equivalent version using a `typedef`:

```c
typedef int PrintError;
PrintError printData();
```
Creating a `typedef` just to document the return type of a single function isn’t worth it (use a comment instead). But if you have multiple functions passing or returning such a type, creating a type alias might be worthwhile.

### Using typedefs for platform independent coding

One of the primary uses for `typedef` is to hide platform specific details. On some platforms, an int is 2 bytes, and on others, it is 4 bytes. Thus, using int to store more than 2 bytes of information can be potentially dangerous when writing platform independent code.

### Using typedefs for easier code maintenance
A `typedef` allows you to change the underlying type of an object without having to update lots of hardcoded types.

Typedefs are most useful when they can be used in many places throughout your code, rather than in fewer places.

### typedef verses #define
In many cases a typedef can be substituted by a #define statement.

```c
#define Counter int; // same as typedef int Counter;
```
`#define` handled by the preprocessor.

`typedef` is handled by the C compiler, this provided  more flexibility when it comes to assigning names to derived data types.

### Typedef best practices
- Use `typedef` judiciously, when they provide a clear benefit to code readability or code maintenance.

- Don't use a `typedef` with a `struct` to save typing `struct`. `struct` is good information for the reader of your code.

- Use for type that combine arrays, struct, pointers or functions.

- Use for portable types
- Use for casting, a typedef can make a complicated type cast simpler.
```c
typedef int (*ptr_to_int_func(void));
char* p;
.... = (ptr_to_int_func) p;
```

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

The struct can then be initialised without the need for the struct keyword. This is **not** best practice as the word `struct` is good information for the reader of your code.

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

[Jump to top](#table-of-contents)

## External References

 - [learncpp.com | Typedefs and type aliases](https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/).
 - [udemy.com | Advanced C programming course | Using typedef](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17961950#overview)