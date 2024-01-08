## File Input/Output

### Writing to files on the local filesystem

```c
FILE *fh_write
```

`FILE` - Used to create a file handle variable.

`*fh_write` - This is a file handle variable, that is used to open and work with files.

You can use the fopen( ) function to create a new file or to open an existing file.

```c
fh_write = fopen("write.txt, "w");
```

`write.txt` - Here, filename is a string literal, which you will use to name your file.

`w` - This access mode, opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file.

Returns `NULL` if error occurs. Therefore validate success using an `if` statement.

```c
if (fh_write == NULL)
{
    printf("Error opening file!\n");
    return 1;
}
```

Then, write to the file using the `fprintf` function.

```c
else
{
    fprintf(fh_write, "Hello, world!\n");
    fclose(fh_write);
}
```

When you have finished with the file, you must close it using the `fclose` function, passing it the file handler variable `fh_write`.





## References

- [C - File I/O](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)