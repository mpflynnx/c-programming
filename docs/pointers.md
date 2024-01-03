## Pointers

A Pointer can be used to store a memory address of a variable.

```c
int *p; // New pointer to store a int type variable
```

To store a memory address to an int type variable we used & operator.

```c
int a = 5;
p = &a; // Assign memory address of a to p
```

Pointer p points to a, which is a int type.

To print the pointers value we use the %p placeholder.

```c
printf("p: %p\n", p);
```

**Output:**
```bash
p: 0x7ffe5cedef48 // Memory address in hexadecimal
```

We can also print the variables memory address as shown.

```c
printf("&a: %p\n", &a);
```

**Output:**
```bash
&a: 0x7ffe5cedef48 // Memory address in hexadecimal
```

If we create another variable in the same program, and print the memory address.

```c
    int b = 10;
    printf("&b: %p\n", &b);
```

**Output:**
```bash
&b: 0x7ffe5cedef4c // Memory address in hexadecimal
```

Notice how close the memory addresses are to each other.

**Output:**
```bash
&a: 0x7ffe5cedef48
&b: 0x7ffe5cedef4c
```

This is due to the stack structure, last in first out. The variable defined first has a lower memory address than the second variable.

## Dereferencing the pointer

To retrieve the value of the variable pointed to by the pointer variable we use * operator.

```c
printf("%d\n", *p); // 5
```

We can use this as shown.

```c
a = a + *p; // 5 + 5
printf("%d\n", *p); // 10
```

## Changing a pointers value

```c
int b = 10;
p = &b; // p now points to b
printf("p: %p\n", p);
```

**Output:**
```bash
&a: 0x7ffe1a33d0d8
p: 0x7ffe1a33d0d8   // p points to a
&b: 0x7ffe1a33d0dc
p: 0x7ffe1a33d0dc   // p now points to b
```

## Using pointers example

```c
*p = *p + 1; // Equivalent to: b = b + 1
printf("b: %d\n", b);
```

**Output:**
```bash
b: 11
```
