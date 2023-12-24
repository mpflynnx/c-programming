## Core file debugging

Source: [you need to stop using print debugging (do THIS instead)](https://www.youtube.com/watch?v=3T3ZDquDDVg)

As an alternative to using printf for debugging.

### Compile options

[Options for Debugging Your Program](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Options-for-Debugging-Your-Program)

Use `-g` to add extra information to the program, all the information needed will be inside core file binary.
This extra debugging information can only be used by GDB.

```bash
gcc -o d d.c -g
```

Upon an error or fault with the program execution, as shown below.

```bash
Segmentation fault (core dumped)
```

This means a core file has been created. The core file contains the full state of the program at the time of the program crashed.

Instruct the linux kernel to produce a unlimited number fo core files. As non-root user run this:

```bash
ulimit -c unlimited
```

View the output location of the core file.
```bash
cat /proc/sys/kernel/core_pattern
```

**Output**
```bash
core
```

To change this to create a core file in the root folder of the program.

```bash
sudo su
// cd to the root of the program
echo "./new_core" > /proc/sys/kernel/core_pattern
```
```bash
cat /proc/sys/kernel/core_pattern
```

**Output**
```bash
./new_core
```

## Using gdb to debug

```bash
gdb ./program_name ./new_core
```

In the debugger type to view the assembly code of the program.

```bash
$pc
info registers
```

## References

- [stackoverflow.com](https://stackoverflow.com/questions/8305866/how-do-i-analyze-a-programs-core-dump-file-with-gdb-when-it-has-command-line-pa)