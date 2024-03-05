## Enums

## Table of Contents

- [Overview](#overview)


- [External References](#external-references)

### Overview

An enumeration (also called an enumerated type or an enum) are a user defined data type that allows a programmer to define a variable and specify the valid values that could be stored in that variable.

Each enumeration needs to be fully defined before we can use it (a forward declaration is not sufficient).

### Unscoped enumerations

Unscoped enumerations are defined via the enum keyword.

It is most common to define one enumerator per line, but in simple cases (where there are a small number of enumerators and no comments are needed), they may all be defined on a single line.



```c
#include <stdio.h>

// unscoped enu
enum Colours 
{   
    red, 
    yellow, 
    blue, // trailing comma recommended
};

int main()
{
    // Memory is allocated for each of these objects.
    enum Colours apple = red;
    enum Colours shirt = yellow;
    enum Colours sky = blue;
    enum Colours grass = green; // invalid

    return 0;
}
```

### Naming enumerations and enumerators
By convention, the names of enumerated types start with a capital letter (as do all program-defined types).

Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.

```c
enum Month { Jan, Feb, Mar, Apr, May, June, July, August, September, October, November, December};
```

### Enums as ints

Unscoped enumerators will implicitly convert to integral values. Enumeration identifiers are treated as integer constants by the compiler.

The first month Jan in enum month is 0.

```c
enum Month thisMonth;
thisMonth = Feb;
```
The int value 1 is assigned to thisMonth variable, because it is the second identifier in the enum list.

We can compare identifiers as ints.

A specific integer value can be associated with an enum identifier at data type definition.

```c
enum Direction {up, down, left = 10, right}; 
// 0 is up, 1 is down, 10 is left, 11 is right
```
**Best practice**
Avoid assigning explicit values to your enumerators unless you have a compelling reason to do so.

**Enum usage example**
```c
#include <stdio.h>
#include <stdbool.h> // needed to use bool

int main()
{

    enum Gender { male, female};

    enum Gender myGender;
    
    myGender = male;

    enum Gender allowed = female;

    bool isFemale = (myGender == allowed);

    if (isFemale){
        printf("You are allowed entry.");
    } else {
        printf("Sorry, you are not allowed entry.");
    }

    printf("Int value of allowed: %d", allowed);

	return 0;

}
```

**Output**
```bash
Sorry, you are not allowed entry.
Int value of allowed: 1
```

### Putting enumerations to use

Because enumerators are descriptive, they are useful for enhancing code documentation and readability. Enumerated types are best used when you have a smallish set of related constants, and objects only need to hold one of those values at a time.

Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck of cards.

Because enumerations are small and inexpensive to copy, it is fine to pass (and return) them by value.

### Avoiding enumerator naming collisions
Avoiding enumerator naming collisions

There are quite a few common ways to prevent unscoped enumerator naming collisions.

One option is to prefix each enumerator with the name of the enumeration itself:

```c
enum Color
{
    color_red,
    color_blue,
    color_green,
};

enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue, // no longer has a naming collision with color_blue
};
```

## External References
- [learncpp | Unscoped enumerations](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)