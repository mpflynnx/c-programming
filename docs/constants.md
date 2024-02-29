## Constants

When reading files using `fgets` we can often make assumptions about the number of characters on each line. Therefore we could define these as constants using `#define` preprocessor statements.
These constants can then be used in all functions of the program, this is known as `global` or `file` scope.

```c
#define LINE_BUFFER 100
```

We can then use this constant when initialising a char array, for example.

```c
char buffer[LINE_BUFFER];
```

```c
fgets( buffer, LINE_BUFFER, fh_read) != NULL
```

### Constant variables

Variables can be defined as constants, and used in expressions much the same way as any variable.
```c
const int x = 5;
```

The `const` keyword prevents the variable `x` from being modified again.

Variables initialised using the `const` keyword have scope. Therefore, are not automatically available to all functions in the program. This is known as `function` scope.