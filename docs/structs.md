## Structs

## Table of Contents

- [Structs](#structs)
    - [Using structs throughout a multi-file program](#using-structs-throughout-a-multi-file-program)
    - [Initialising struct members](#initialising-struct-members)
    - [Missing initialisers in an initialiser list](#missing-initialisers-in-an-initialiser-list)
    - [Initialising a struct with another struct of the same type](#initialising-a-struct-with-another-struct-of-the-same-type)
    - [Const structs](#const-structs)
    - [Using typedef with struct](#using-typedef-with-struct)
    - [Passing structs (by value)](#passing-structs-by-value)
    - [Problems with passing structs](#problems-with-passing-structs)
    - [Passing structs (by pointer/reference)](#passing-structs-by-pointerreference)
    - [Using dynamic memory allocation with structs](#using-dynamic-memory-allocation-with-structs)
    - [Struct pass by reference](#struct-pass-by-reference)
    - [Structs pointers members](#struct-pointer-members)
    - [Returning structs](#returning-structs)

- [External References](#external-references)



### Structs

A struct (short for structure) allows related information to be grouped together in a record. We have seen arrays only allow the same type of information to be stored together, such as integers. A `struct` allows us to store different types of information. For example `person1` may have a first name (char), last name(char), age(integer), height(float) etc, by grouping them together, this is more readable.

**struct example usage**

To define a point in a 2 dimensional space, we have x and y co-ordinates. Use `struct` keyword to create a new [program-defined](https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/) type Point, with two members x and y for the co-ordinates. 

The variables that are part of the struct are called data members (or member variables).

A member is a variable, function, or type that belongs to a struct. All members must be declared within the struct definition.

**Notice** the uppercase first letter for the struct name, i.e Point not point. Program-defined types are typically given names starting with a capital letter and don’t use a suffix. Program-defined type definitions must end in a semicolon.

```c
struct Point
{
    int x; // note: no initialiser here
    int y;
}; // Program-defined type definitions must end in a semicolon.
```

To create a new `Point` struct named `p1`.

```c
struct Point p1;
```
The name `p1` refers to the entire struct object (which contains the member variables). To access a specific member variable, we use the member selection operator (`operator.`) in between the struct variable name and the member name (dot notation). For example, to access p1's x member, we’d use `p1.x`.

We can initialise the values for the x and y members.

```c
p1.x = 5;
p1.y = 3;
```
Struct member variables work just like normal variables, so it is possible to do normal operations on them, including assignment, arithmetic, comparison, etc…

Because `x` and `y` members are integers we can use the `%d` placeholder with `printf`.

```c
printf("(%d, %d)\n", p1.x, p1.y);
```

We can create as many struct Points as required.

```c
struct Point p2;
struct Point p3;
```

### Using structs throughout a multi-file program
Every code file that uses a program-defined type like a struct, needs to see the full type definition before it is used. A forward declaration is not sufficient. This is required so that the compiler knows how much memory to allocate for objects of that type.

To propagate type definitions into the code files that need them, program-defined types are typically defined in header files, and then #included into any code file that requires that type definition. These header files are typically given the same name as the program-defined type (e.g. a program-defined type named Fraction would be defined in Fraction.h)

**Best practice**
A program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible.

A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed.

### Initialising struct members

When initialising a struct from a list of values, the initialisers are applied to the members in order of declaration. Similar to how values are assigned in arrays.

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

**Best practice**
When adding a new member to an aggregate, it’s safest to add it to the bottom of the definition list so the initialisers for other members don’t shift.

### Missing initialisers in an initialiser list

If an [aggregate](https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/#aggregate) is initialised but the number of initialisation values is fewer than the number of members, then all remaining members will be value-initialized.

```c
#include <stdio.h>

struct Employee
{
    int id;
    int age;
    double wage;
};

int main()
{
    struct Employee joe = { 2, 28 }; // joe.wage will be value-initialised to 0.000000

    printf("(%d, %d, %f)\n", joe.id, joe.age, joe.wage); // (2, 28, 0.000000)

    return 0;
}
```

In the above example, `joe.id` will be initialised with value 2, `joe.age` will be initialised with value 28, and because `joe.wage` wasn’t given an explicit initialiser, it will be value-initialised to 0.000000.

This means we can use an empty initialisation list to value-initialise all members of the struct:

```c
struct Employee joe = {}; // value-initialise all members
```

### Initialising a struct with another struct of the same type

A struct may also be initialised using another struct of the same type:

```c
#include <stdio.h>

struct Employee
{
    int id;
    int age;
    double wage;
};

int main()
{
    struct Employee joe = { 2, 28 }; // joe.wage will be value-initialised to 0.000000
    printf("(%d, %d, %f)\n", joe.id, joe.age, joe.wage); // (2, 28, 0.000000)

    struct Employee bob = joe; // copy initialisation
    printf("(%d, %d, %f)\n", bob.id, bob.age, bob.wage); // (2, 28, 0.000000)

    return 0;
}
```

### Const structs

Variables of a struct type can be const, and just like all const variables, they must be initialised.

```c
#include <stdio.h>

struct Rectangle
{
    double length;
    double width;
};

int main()
{
    const struct Rectangle unit = { 1.0, 1.0 };
    const struct Rectangle zero = { }; // value-initialize all members

    unit.length = 2.0; // not modifiable

    return 0;
}
```

### Using typedef with struct

We have seen that when we initialise a struct, we always have to type keyword `struct` then the struct name. We can use `typedef` to save us typing `struct` every time we initialise a struct.

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

### Passing structs (by value)

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

We can now call from the main function the `print_student` function, passing in struct `Student` `s1`.

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
Structs are pass by value, passing struct to functions work like int types. The passed struct cannot be updated in the called function, as a copy of the struct is made when the function is called. The function uses the copy. This means that the struct is duplicated in memory. This can be problematic if the struct contains many large arrays for example. This is why programmers mostly use dynamic memory allocation and pass by reference with structs.

### Passing structs (by pointer/reference)

A big advantage of using structs over individual variables is that we can pass the entire struct to a function that needs to work with the members. Structs are generally passed by pointer (typically by const) to avoid making copies.

```c
#include <stdio.h>

typedef struct 
{
    int id;
    int age;
    double wage;
}Employee;

void printEmployee(const Employee* employee) // note pass by pointer here
{
    // You can also use the arrow operator (->) to access struct members
    printf("ID:   %d\n", employee->id);
    printf("Age:  %d\n", employee->age);
    printf("Wage: %.2f\n", employee->wage); // Display wage with 2 decimal places

}

int main()
{
    Employee joe = { 14, 32, 24.15 };
    Employee frank = { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(&joe);

    printf("\n");

    // Print Frank's information
    printEmployee(&frank);

    return 0;
}
```

Because we are passing the entire struct object (rather than individual members), we only need one parameter no matter how many members the struct object has. And, in the future, if we ever decide to add new members to our Employee struct, we will not have to change the function declaration or function call! The new member will automatically be included.

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

How the `->` (arrow operator) works is: At the block of memory pointed to by `s1`, get the `age` member variable in that block of memory and set it to `20`.

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

### Returning structs

Consider the case where we have a function that needs to return a point in 3-dimensional Cartesian space. Such a point has 3 attributes: an x-coordinate, a y-coordinate, and a z-coordinate. But functions can only return one value. So how do we return all 3 coordinates back the user?

One common way is to return a struct:

```c
#include <stdio.h>

typedef struct
{
    double x;
    double y;
    double z;
}Point3d;

Point3d getZeroPoint()
{
    // We can create a variable and return the variable (we'll improve this below)
    Point3d temp = { 0.0, 0.0, 0.0 };
    return temp;
}

int main()
{
    Point3d zero = getZeroPoint();

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        printf("The point is zero\n");
    else
        printf("The point is not zero\n");

    return 0;
}
```

This prints:

```bash
The point is zero
```
Structs are usually returned by value, so as not to return a dangling reference.

In the getZeroPoint() function above, we create a new named object (temp) just so we could return it.

The name of the object (temp) doesn’t really provide any documentation value here.

We can make our function slightly better by returning a temporary (unnamed/anonymous) object instead. Used a compound literal `(Point3d){}` to directly initialize the struct with zero values:
```c
Point3d getZeroPoint()
{
    return (Point3d){}; // return an unnamed Point3d
}
```
In this case, a temporary Point3d is constructed, copied back to the caller, and then destroyed at the end of the expression. Note how much cleaner this is (one line vs two, and no need to understand whether temp is used more than once). 

Learn anonymous objects in more detail at [learncpp.com | Temporary class objects](https://www.learncpp.com/cpp-tutorial/temporary-class-objects/)

[Jump to top](#table-of-contents)

## External References

  - [learncpp.com | Introduction to program-defined (user-defined) types](https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/)
 - [learncpp.com | Introduction to structs, members, and member selection](https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/)
 - [learncpp.com | Struct aggregate initialization](https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/)
 - [learncpp.com | Passing and returning structs](https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/)
 - [strcpy](https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm)
 - [learncpp.com | Temporary class objects](https://www.learncpp.com/cpp-tutorial/temporary-class-objects/)