## Core file debugging

As a alternative to using printf for debugging.

### Compile options

Use `-g` to add debug flags to the program, all the information needed will be inside core file binary.

```bash
gcc -o d d.c -g
```

Upon an error or fault with the program execution, as shown below.

```bash
Segmentation fault (core dumped)
```

This means a core file has been created. The core file contains the full state of the program at the time of the program crashed.

Instruct the kernel to produce a unlimited number fo core files
```bash
ulimit -c unlimited
```

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
