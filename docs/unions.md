## Unions

## Table of Contents

- [Overview](#overview)
- [Defining a union](#defining-a-union)
- [Anonymous unions](#anonymous-unions)
- [Accessing union members](#accessing-union-members)
- [Union initialisation](#union-initialisation)

- [External References](#external-references)

### Overview

- Stores different types of data in the same storage area.
- Saves on space for alternating data types.
- Size determined by the largest type. 

### Defining a union
The declaration is identical to that of a struct, except the keyword union is used.

```c
union union_tag { // union_tag optional
    type1 identifier_1;
    type2 identifier_2;
} optional_variable_definitions;
```

The union definition is placed in the header and included in all source files that use the union type.

**Example**
```c
union Data {
    int i; // 4 bytes
    float f; // 8 bytes
    char str[20]; // 20 bytes
} data1, data2; //global union variables optional
```

A variable of type Data, can store an integer **or** a float, **or** a string of chars, not **all**. A struct could store **all** but not a union.

The memory occupied by a union will be large enough to hold the largest member, in this case 20 bytes as char str[20] is the largest member.

- No memory is allocated until variables are created.
- There is no limit to the number of members.
- Struct can contain unions, as can arrays.
- Pointers to unions work the same as with structs.

**Example**
```c
#include <stdio.h>

union Car {
    int i_value; // 4 bytes
    float f_value; // 4 bytes
    char c_value[40]; // 40 bytes largest member
    }; //car1, car2, *car3;

int main()
{
    union Car car1, car2, *car3; // declare unions
    printf("Size of union: %zu bytes.\n", sizeof(car1));
    return 0;
}
```

**Output**
```bash
Size of union: 40 bytes.
```
The example code below, shows how the union memory storage is changed when assigning different type to the members.

```c
#include <stdio.h>
#include <string.h>

union sample {
    int i;
    char ca[4];
    float f;
};

int main()
{

    union sample u;
    
    u.i = 42;
    printf("%08x %f %s\n", u.i, u.f, u.ca);
    
    strcpy(u.ca, "Abc"); // copy 3 chars leaving space for null operator
    printf("%08x %f %s\n", u.i, u.f, u.ca);
    
    u.f = 1.0/3.0;
    printf("%08x %f %s\n", u.i, u.f, u.ca);

	return 0;
}
```
**Output**
```bash
0000002a 0.000000 * // 2a hex is 42
00636241 0.000000 Abc // 00 is null operator, 63 is `A`, 62 is `b`, 41 is 'c'.
3eaaaaab 0.333333 □□□>0□□□ // 32aaaaab is 0.3333 in hex
```

### Anonymous unions
Introduced in C11. Anonymous unions exist only inside another union or struct. It has no union tag or variables assigned to it.

**Example**
```c
#include <stdio.h>

struct Owner{
    char socsecurity[12];
};

struct Lease_company{
    char name[40];
    char headquarters[40];
};

struct Car_data {
    char make[15];
    int status;
    union { // Anonymous union
        struct Owner own_car;
        struct Lease_company lease_car;
    };
};

int main()
{
    ...
```

```c
struct {
    char* name;
    enum symbolType type;
    union {
        int i;
        float f;
        char c;
    }; data; // union variable 
} table [entries]; // array named table
```

### Accessing union members
We access/assign data to members of a union, the same was we do with structs:
- with the (.) dot operator to access members
- with the (->) indirection operator to access pointer variables

**Union member assignment example**
```c
#include <stdio.h>

union {
    int code;
    float cost;
} item; // global variable

int main()
{
    item.code = 1234;

    return 0;
}
```
**Accessing pointer members example**
```c
#include <stdio.h>

union {
    int code;
    float cost;
} item, *ptrst;

int main()
{
    ptrst = &item;
    ptrst->code = 9876; // assigns an int to code member

    return 0;
}
```
The following expressions are equivalents
- ptrst->code = 9876; // preferred method
- item.code = 9876;
- (*ptrst).code = 9876;

```c
#include <stdio.h>

union mixed {
    char c;
    float f;
    int i;
};

int main()
{
    union mixed x; // can store one only at a time of the three members
    x.c = 'q';
    printf("Char at c: %c\n", x.c); // prints, Char at c: q
    x.f = 3.142; // union memory overwritten with 3.142
    printf("Float at f: %f\n", x.f); // prints, Float at f: 3.142000
    x.i = 1234 / 2; // union memory overwritten with 617
    printf("Int at i: %d\n", x.i); // prints, Int at i: 617
    return 0;
}
```

### Union initialisation

```c
#include <stdio.h>

union Number {
    int x;
    double y;
};

int main()
{

    union Number value = {12}; // int is first member in union, so needs a int

    // alternatives
    union Number value = {.x = 12}; // int is first member in union, so needs a int
    union Number value = {.y = 3.142}; 

    return 0;
}
```
**Using pointers example**
```c
#include <stdio.h>

union Number {
    int x;
    double y;
};


int main()
{

    union Number value1;
    union Number *value2 = &value1;

    value2->y = 10.0;
    printf("Double at value2 y: %f\n", value2->y);

    return 0;
}
```


**Using functions example**
```c
#include <stdio.h>

union Number {
    int x;
    double y;
};

// Initialise another union of Number via function foo
void foo(union Number n){
    union Number value2 = n;
    printf("Double at value2 y: %f\n", value2.y);
}

int main()
{

    union Number value1 = {.y = 12.2};
    printf("Double at value1 y: %f\n", value1.y);

    foo(value1); // initialise another union with a union via a function

    return 0;
}
```


## External References
- [udemy.com | Advanced C programming course | Unions](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17962172#notes)
- [geeksforgeeks.org | C Programming Language Tutorial](https://www.geeksforgeeks.org/c-programming-language/?ref=lbp)
- [geeksforgeeks.org | C Unions](https://www.geeksforgeeks.org/c-unions/?ref=lbp)
- [geeksforgeeks.org | Difference Between Structure and Union in C](https://www.geeksforgeeks.org/structure-vs-union-in-c/)
- [geeksforgeeks.org | Anonymous Union and Structure in C](https://www.geeksforgeeks.org/g-fact-38-anonymous-union-and-structure/?ref=lbp)