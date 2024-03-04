## Unions

## Table of Contents

- [Overview](#overview)

- [External References](#external-references)

### Overview

- Stores different types of data in the same storage area.
- Saves on space for alternating data types.
- Size determined by the largest type. 

### Defining a union
The declaration is identical to that of a struct, except the keyword union is used.

```c
union union_tag{ // union_tag optional
    type1 identifier_1;
    type2 identifier_2;
} optional_variable_definitions;
```

The definition is placed in the header and included in all source files that use the union type.

**Example**
```c
union Data {
    int i; // 4 bytes
    float f; // 8 bytes
    char str[20]; // 20 bytes
} data; // variable data created
```

A variable of type Data, can store an integer **or** a float, **or** a string of chars, not **all**. A struct could store **all** but not a union.

The memory occupied by a union will be large enough to hold the largest member, in this case 20 bytes as char str[20] is the largest member.

## External References
- [udemy.com | advanced C programming course | Unions](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17962172#notes)
- [geeksforgeeks.org | Difference Between Structure and Union in C](https://www.geeksforgeeks.org/structure-vs-union-in-c/)