### printf special characters

- New line, insert a new line after printed text.
```c
\n
```

- tab, indents text to the right.
```c
\t
printf("\tindented text\n");
```

**Output**
```bash
        indented text
```

- escape, allows printing of double quotes etc.
```c
\"
printf("\"text inside double quote\".\n");
```

**Output**
```bash
"text inside double quotes."
```

Watch out for this, compile error occur.
```c
printf("\");
```
To print a backslash \, you need to escape it first.
```c
\\
printf("Escape symbol is \"\\\"\n");
```

**Output**
```bash
Escape symbol is "\"
```

### printf placeholder formatting options

%[flags] [width] [.precision] specifier

### printf placeholders specifiers

- int type
```c
%d
```
- float or double types
```c
%f
```
- double type
```c
%lf
```
- char type
```c
%c
```

- strings
```c
%s
```

### printf field width

Field width helps to print tables.

Specify the field width for a given specifier.

Field width set to 10.
```c
printf("|||%10d|||\n", 5);
```

**Output**
```bash
|||         5|||
```

### printf flags

- right align, no flag (default)
- Left align flag is: -

```c
printf("|||%-10d|||\n", 5);
```

**Output**
```bash
|||5         |||
```

### printf real number precision

Define the precision of float or doubles. 

For two floating points of precision. i.e modify 5.4567 to 5.46, use .2 as precision.

```c
printf("|||%10.2f|||\n", 5.456700);
```

**Output**
```bash
|||      5.46|||
```
