## Pointer notation

We have seen that an array can be passed to a function.

```c
void add_one(int array[], int length);
```

```c
int a[] = {1,2,3};
add_one(a, 3);
```

An array decays to a pointer. We are passing the memory address of the arrays first index 0. We can also define the function as shown below.

```c
void add_one(int *array, int length);
```

Therefore a program would look like this.
```c
#include <stdio.h>

void add_one(int *array, int length);

int main(void)
{

    int a[] = {1,2,3};
    printf("a: %p\n", a);

    add_one(a, 3);

    for (int i = 0; i < 3; i++)
        printf("a[%d]=%d\n", i, a[i]);

    return 0;
}

void add_one(int *array, int length)
{
    printf("Array passed to function: %p\n", array); 
    for(int i = 0; i < length; i++) array[i] += 1;
}
```

### Array notation

We can treat arrays as pointers and pointers as arrays. In must cases but not always.

We can define a pointer `p` to array `a` as shown:

```c
int *p;
p = a; // no need for &a as array is a memory address
```

`p` now points to the memory address of array index 0, a[0] which  is the same as `a`.

```c
printf("p: %p\n", p); // p: 0x7ffd57bafcec
printf("a: %p\n", a); // a: 0x7ffd57bafcec
```

We can now access the array elements using `p`.

```c
int a[] = {1,2,3};
int *p;
p = a;
printf("%d\n", p[2]); // 3
```

Example above `p[2]` is known as array notation.
This will shift 2 memory locations from memory location assign to `p`.

### Pointer notation

Pointer notation (pointer arithmetic) is another way of obtaining a value shifted over from a given memory address. 

```c
*(p + 1)
```

The brackets are for precedence, firstly apply (p + 1) then use `*` operator to get the value held at that memory location. As `p` initially pointed to an array index 0 the next memory location will be that of array index [1]. 

```c
#include <stdio.h>

int main(void)
{

    int a[] = {1,2,3};
    int *p;
    p = a;

    printf("*(p + 1) = %d\n", *(p + 1));

    return 0;
}
```

**Output:**
```bash
*(p + 1) = 2
```

I didn't need to create pointer `p` to use pointer notation, the same result could be achieved just using the array `a` as shown below.

```c
#include <stdio.h>

int main(void)
{

    int a[] = {1,2,3};

    printf("*(a + 2) = %d\n", *(a + 2));

    return 0;
}
```

**Output:**
```bash
*(a + 2) = 3
```

Pointers and array cannot always be used as shown above.

Array `a` cannot be changed once created, the memory address remains the same. Arrays are not assignable, but we have seen that pointers can be changed after creation.

Pointer notation is not always recommended, as some find it difficult to read. Whereas array notation is more readable.

### Pointer notation use case example
There are good reasons to use pointer notation. For example in the following program, we have an array of length 10. If we use pointer notation when we call the function `add_one`, we are only updating array elements from the memory location given when the function is called.

```c
#include <stdio.h>

void add_one(int *array, int length);

int main(void)
{

    int a[] = {1,2,3,4,5,6,7,8,9,10};

    add_one(a + 5, 5);

    for (int i = 0; i < 10; i++)
        printf("a[%d]=%d\n", i, a[i]);

    return 0;
}

void add_one(int *array, int length)
{
    printf("Array passed to function: %p\n", array); 
    for(int i = 0; i < length; i++) array[i] += 1;
}
```

**Output:**
```bash
Array passed to function: 0x7fffcf285604
a[0]=1
a[1]=2
a[2]=3
a[3]=4
a[4]=5
a[5]=7
a[6]=8
a[7]=9
a[8]=10
a[9]=11
```

The line below shifts the given memory address by 5, which is the array index [5]. As the function doesn't care about the full length of the array, we can pass the length as 5.

```c
add_one(a + 5, 5); 
```

Therefore the last five elements will be updated by the function `add_one` and the first five elements left unchanged.