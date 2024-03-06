## File Input/Output

### Writing to files on the local filesystem

```c
FILE *fh_write;
```

`FILE` - Used to create a file handle variable.

`*fh_write` - This is a file handle variable, that is used to open and work with files.

You can use the fopen() function to create a new file or to open an existing file.

```c
fh_write = fopen("write.txt", "w");
```

`write.txt` - Here, filename is a string literal, which you will use to name your file.

`w` - This access mode, opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file overwriting any existing content.

Returns `NULL` if error occurs. Therefore validate success using an `if` statement.

```c
if (fh_write == NULL)
{
    printf("Error opening file!\n");
    return 1;
}
```

Then, write to the file using the `fprintf` function. This function works very much like `printf`, therefore we can use placeholders in the string text.

```c
else
{
    fprintf(fh_write, "Hello, world!\n");
    fclose(fh_write);
}
```

Alternatively we can use the `fputs` function to write to a file. The function takes 2 arguments. The first argument is a pointer to the string which is to be written and the second argument is the pointer of the file where the string is to be written. It returns 1 if the write operation was successful, otherwise, it returns 0. fputs() writes a single line of characters in a file.

```c
fputs("Hello, world!\n", fh_write);
fclose(fh_write);
```

When you have finished with the file, you must close it using the `fclose` function, passing it the file handler variable `fh_write`.

You can also write program variables to files.

```c
int x = 100;
fprintf(fh_write, "Value x: %d\n", x);
```

**write.txt**
```bash
Hello, world!
Value x: 100
```

### Using loops to write to files

The else statement can be used to write lines using a loop.
```c
...
    else 
    {
        for (int i; i < 10; i++)
            fprintf(fh_write, "%d\n", (i+1));
        fclose(fh_write);
    }
...
```

**write.txt**
```bash
1
2
3
4
5
6
7
8
9
10
```

### Adding content to a file

We can add content to the first available empty line in a file using append mode `"a"` with `fopen`.

```c
fh_write = fopen("write.txt, "a");
```

### Reading text from a file using fgets()

We can read content from a file using read mode `"r"` with the `fopen` and `fgets` functions.

```c
FILE *fh_read; // Handler for reading a file
fh_read = fopen("write.txt", "r");
```

To read a files contents line by line you first need to create a char array. A common array name to use is `buffer` for this type of use case. The files line contents will be stored in the array.

```c
char buffer[100];
```
Use function `fgets` by passing in the array name `buffer`, integer for the line character limit, and file handler name. 

```c
fgets( buffer, 100, fh_read);
```

The `fgets` function only reads in strings, it will stop on the detection of a new line character in the read file. Therefore we need to loop through every line until the function returns `NULL`. 

Printing the contents of a file to console.
```c
while (fgets( buffer, 100, fh_read) != NULL)
{
    printf("%s", buffer);
}
```

Assuming the read file contains numbers on each line, as shown.

**write.txt**
```bash
1
2
3
4
5
6
7
8
9
10
```

### Reading integers from a file using fscanf()

Alternatively `fscanf` function could be used, this works similar to scanf. If the file contents are known, then the use of placeholders can be used. For example if a file contains the content as shown below, each  line can be assigned to a integer variable.

**io.txt**
```bash
23
65
34
45
66
```

By using `fscanf` each line can be read and the integer stored in a variable, the variable can then be printed to the terminal using `printf`. We need to loop through every line until the function returns `EOF` (END OF FILE).

```c
#include <stdio.h>

int main(void)
{

    FILE *fh_input; // Handler for reading a file
    fh_input = fopen("io.txt", "r");

    int finput = 0;
    int lines = 0;
    int numbers[100];

    while (fscanf(fh_input, "%d", &finput) != EOF)
    {
        numbers[lines] = finput;
        printf("file line %d: %d\n", lines+1, finput);
        lines++;
    }

    fclose(fh_input);


    return 0;
}
```

**Output**
```bash
file line 1: 23
file line 2: 65
file line 3: 34
file line 4: 45
file line 5: 66
```

### Reading integers from a file using fgets()

We can read a file line by line then store the contents of each line in an integer array `data`. Upon reading the file line, we need to cast the read string to a integer using `atoi` function.

```c
int data[10];
int i = 0;
while (fgets( buffer, 100, fh_read) != NULL)
{
    data[i] = atoi(buffer);
    i++;
}
```

We could then print the data array elements.

```c
int num_lines = i;
printf("\n...Printing data array...\n");
for (int j = 0; j < num_lines; j++)
    printf("data[%d]=%d\n", j, data[j]);
```

**Output**
```bash
...Printing data array...
data[0]=1
data[1]=2
data[2]=3
data[3]=4
data[4]=5
data[5]=6
data[6]=7
data[7]=8
```

We could also find the average of all the integers in the data array and print the result to console.

```c
for (int j = 0; j < num_lines; j++)
{
    total += data[j];
}
printf("average: %d\n", total / num_lines);   
```

## References

- [C - File I/O](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)