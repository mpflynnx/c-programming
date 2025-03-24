## Pointers

A pointer can be used to store a memory address of a variable.

Best practice for storing pointers on a 64-bit machine: Use uintptr_t or intptr_t from <stdint.h>

```c
int *ptr1; // New pointer to store a int type variables address
int* ptr2; // same as above  but * after variable type.
```
**Best practice**
When declaring a pointer type, place the asterisk after the variable type.
```c
int* ptr; // an uninitialised pointer (holds a garbage address)
```

**Best practice**
Always initialise your pointers. Value initialise your pointers (to be null pointers) if you are not initialising them with the address of a valid object.

```c
int* ptr2 = NULL; // NULL keyword represents address zero
int* ptr3 = 0; // value initialisation, null pointer represents no address or zero
```

To store a memory address to an int type variable we used the `&` operator.

```c
int* p = NULL;
int a = 5;
p = &a; // Assign memory address of a to p
```

Pointer `p` points to `a`, which is a int type.

To print the pointers value we use the `%p` placeholder.

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

To retrieve the value of the variable pointed to by the pointer variable we use `*` operator.

```c
printf("%d\n", *p); // 5
```

We can use this as shown.

```c
a = a + *p; // 5 + 5
printf("%d\n", *p); // 10
```

## Changing a pointers value
We can change the value of the `p` pointer.

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

### Using pointers example

```c
*p = *p + 1; // Equivalent to: b = 10 + 1
printf("b: %d\n", b);
```

**Output:**
```bash
b: 11
```
