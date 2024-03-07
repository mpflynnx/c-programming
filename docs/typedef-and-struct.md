## Typedefs

## Table of Contents
- [Typedefs](#typedefs)
    - [Using typedefs to make complex types easier to read](#using-typedefs-to-make-complex-types-easier-to-read)
    - [Using typedefs to document the meaning of a value](#using-typedefs-to-document-the-meaning-of-a-value)
    - [Using typedefs for platform independent coding](#using-typedefs-for-platform-independent-coding)
    - [Using typedefs for easier code maintenance](#using-typedefs-for-easier-code-maintenance)
    - [typedef verses #define](#typedef-verses-define)
    - [Typedef best practices](#typedef-best-practices)

- [External References](#external-references)


### Typedefs

A typedef (which is short for “type definition”) is a way of creating an alias for a type. To create a typedef alias, we use the `typedef` keyword.

The name `typedef` suggests that a new type is being defined, but that’s not true. A typedef is just an alias.

**typedef example usage**

Declare `typedef` near the top of the file below any preprocessor statements.
```c
typedef type alias-name;
```
It’s easy to forget whether the name of the typedef or the name of the type to alias comes first.

```c
typedef int inches; // aliased type first (i.e int)
```

The above creates a new type `inches` which is a alias for `int`. Using typedef helps improve the readability of the code.

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
printf("person1: %d\n", person1); // %d placeholder used for inches and int
```
### Using typedefs to make complex types easier to read

`typedef` allows you to take complex types and give them a simpler name, which makes your code easier to read and saves typing.

```c
#include <stdio.h>

typedef int* int_pointer; // alias for a int pointer

int main() {
    // declare multiple pointers on one line using typedef.
    int_pointer p, q; // both p and q become pointers
    
    int *r, s; // only r is a pointer, s is a int
..
```

Syntax for a `typedef` can get ugly with more complex types. For example, here is a hard-to-read typedef.

```c
typedef int (*FcnType)(double, char); // FcnType hard to find
```

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
Creating a `typedef` just to document the return type of a single function isn’t worth it (use a comment instead). But if you have multiple functions passing or returning such a type, creating a `typedef` might be worthwhile.

### Using typedefs for platform independent coding

One of the primary uses for `typedef` is to hide platform specific details. On some platforms, an int is 2 bytes, and on others, it is 4 bytes. Thus, using int to store more than 2 bytes of information can be potentially dangerous when writing platform independent code.

In order to make sure each aliased type resolves to a type of the right size, typedefs of this kind are typically used in conjunction with preprocessor directives:
```c
#ifdef INT_2_BYTES
typedef char int8_t;
typedef int int16_t;
typedef long int32_t;
#else
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
#endif
```
On machines where integers are only 2 bytes, INT_2_BYTES can be #defined (as a compiler/preprocessor setting), and the program will be compiled with the top set of typedefs. On machines where integers are 4 bytes, leaving INT_2_BYTES undefined will cause the bottom set of typedefs to be used.

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
- Don't use a `typedef` with a `struct` to save typing `struct`. `struct` keyword is good information for the reader of your code.
- Use for a type that combine arrays, struct, pointers or functions.
- Use for portable types
- Use for casting, a typedef can make a complicated type cast simpler, as shown below.

```c
typedef int (*ptr_to_int_func(void));
char* p;
.... = (ptr_to_int_func) p;
```

[Jump to top](#table-of-contents)

## External References

 - [learncpp.com | Typedefs and type aliases](https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/).
 - [udemy.com | Advanced C programming course | Using typedef](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17961950#overview)
 