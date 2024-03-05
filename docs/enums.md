## Enums

## Table of Contents

- [Overview](#overview)
- [Unscoped enumerations](#unscoped-enumerations)
- [Naming enumerations and enumerators](#naming-enumerations-and-enumerators)
- [Enums as integers](#enums-as-integers)
- [Putting enumerations to use](#putting-enumerations-to-use)
- [Avoiding enumerator naming collisions](#avoiding-enumerator-naming-collisions)
- [Printing enumerator names](#printing-enumerator-names)
- [Problem with enumerations](#problem-with-enumerations)

- [External References](#external-references)

### Overview

An enumeration (also called an enumerated type or an enum) are a user defined data type that allows a programmer to define a variable and specify the valid values that could be stored in that variable.

Each enumeration needs to be fully defined before we can use it (a forward declaration is not sufficient).

### Unscoped enumerations

Unscoped enumerations are defined via the enum keyword.

It is most common to define one enumerator per line, but in simple cases (where there are a small number of enumerators and no comments are needed), they may all be defined on a single line.

```c
#include <stdio.h>

// unscoped enum
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

### Enums as integers

When we define an enumerator, each enumerator is automatically assigned an integer value based on its position in the enumerator list. By default, the first enumerator is assigned the integral value 0, and each subsequent enumerator has a value one greater than the previous enumerator:

The first month Jan in enum month is 0.

```c
enum Colour
{
    black, // assigned 0
    red, // assigned 1
    blue, // assigned 2
    green, // assigned 3
    white, // assigned 4
    cyan, // assigned 5
    yellow, // assigned 6
    magenta, // assigned 7
};

int main()
{
    enum Colour shirt = blue; // This actually stores the integral value 2

    return 0;
}
```

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

    enum Gender myGender = male;

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

```c
#include <stdio.h>

enum MonsterType
{
    orc,
    goblin,
    troll,
    ogre,
    skeleton,
};

int main()
{

    enum MonsterType monster = troll;

    if (monster == troll)
        printf("Troll attacks!\n");
    else
        printf("Play on!\n");

	return 0;

}
```

### Avoiding enumerator naming collisions
Avoiding enumerator naming collisions

There are a few common ways to prevent unscoped enumerator naming collisions.

One option is to prefix each enumerator with the name of the enumeration itself:

```c
enum Colour
{
    colour_red,
    colour_blue,
    colour_green,
};

enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue, // no longer has a naming collision with color_blue
};
```

### Printing enumerator names

Most of the time, printing an enumeration as an integral value (such as 1) isn’t what we want. Instead, we typically will want to print the name of whatever the enumerator represents (red). But to do that, we need some way to convert the integral value of the enumeration (1) into a string matching the enumerator name ("red").

In the following example, we will also return our Colour as a const char*, to give the caller more flexibility to do whatever they want with the name (including print it):

```c
#include <stdio.h>

enum Colour
{
    black, // assigned 0
    red, // assigned 1
    blue, // assigned 2
};

const char* getColour(enum Colour colour)
{
    switch (colour)
    {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???";
    }
}

int main()
{
    enum Colour shirt = red;

    printf("Your shirt is %s\n", getColour(shirt));

    return 0;
}
```

### Problem with enumerations
Although unscoped enumerations are distinct types in C, they are not type safe, and in some cases will allow you to do things that don’t make sense. Consider the following case:

```c
#include <stdio.h>

enum Colour
{
    black,
    red,
    blue,
};

enum Fruit
{
    banana,
    apple,
};

int main()
{
    enum Colour colour = black;
    enum Fruit fruit = banana;

    if (colour == fruit) // The compiler will compare colour and fruit as integers
        printf("colour and fruit are equal\n"); // and find they are equal!
    else
        printf("colour and fruit are not equal\n");

    return 0;
}
```
**Output**
```bash
colour and fruit are equal
```

When colour and fruit are compared, the compiler will look to see if it knows how to compare a Colour and a Fruit. It doesn’t. Next, it will try converting Colour and/or Fruit to integers to see if it can find a match. Eventually the compiler will determine that if it converts both to integers, it can do the comparison. Since colour and fruit are both set to enumerators that convert to integer value 0, color will equal fruit.

This doesn’t make sense semantically since colour and fruit are from different enumerations and are not intended to be comparable. With standard enumerators, there’s no easy way to prevent this.

A solution is to compare strings:

```c
#include <stdio.h>

enum Colour
{
    black,
    red,
    blue,
};

enum Fruit
{
    banana,
    apple,
};

const char* getColour(enum Colour colour)
{
    switch (colour)
    {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???";
    }
}

const char* getFruit(enum Fruit fruit)
{
    switch (fruit)
    {
        case banana: return "banana";
        case apple:  return "apple";
        default:     return "???";
    }
}

int main()
{
    enum Colour colour = black;
    enum Fruit fruit = banana;

    if (getColour(colour) == getFruit(fruit)) // The compiler will compare colour and fruit as strings
        printf("colour and fruit are equal\n");
    else
        printf("colour and fruit are not equal\n"); // and find they are not equal!

    return 0;
}
```
**Output**
```bash
colour and fruit are not equal
```

## External References
- [udemy.com | C Programming For Beginners | enums](https://www.udemy.com/course/c-programming-for-beginners-/)
- [learncpp | Unscoped enumerations](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)
- [learnccp | Unscoped enumeration input and output](https://www.learncpp.com/cpp-tutorial/unscoped-enumeration-input-and-output/)