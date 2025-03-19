## Debugging with gdb

## Table of Contents
- [Compiler options](#compiler-options)
- [Starting and quitting the debugger](#starting-and-quitting-the-debugger)
- [Viewing help documentation](#viewing-help-documentation)
- [Running the program in the debugger](#running-the-program-in-the-debugger)
- [Show program argument list](#show-program-argument-list)
- [info command](#info-command)
    - [View info on source file](#view-info-on-source-file)
    - [View all local variables and values](#view-all-local-variables-and-values)
- [list command](#list-command)
    - [List all lines of code of the main function](#list-all-lines-of-code-of-the-main-function)
    - [List lines of code of the main function](#list-lines-of-code-of-the-main-function)
    - [List lines of code around a given line number of main.c](#list-lines-of-code-around-a-given-line-number-of-mainc)
    - [List next 10 lines of code](#list-next-10-lines-of-code)
    - [List previous 10 lines of code](#list-previous-10-lines-of-code)
    - [List previous x number of lines of code](#list-previous-x-number-of-lines-of-code)
    - [List next x number of lines of code](#list-next-x-number-of-lines-of-code)
    - [List in range lines of code](#list-in-range-lines-of-code)
    - [List lines of code in a given function](#list-lines-of-code-in-a-given-function)
- [print command](#print-command)
    - [View variables values](#view-variables-values)
    - [View structs and union](#view-structs-and-union)
- [Viewing Memory Contents](#viewing-memory-contents)
- [Setting variable values](#setting-variable-values)
    - [Setting main function variable values](#setting-main-function-variable-values)
    - [Setting a given functions variable values](#setting-a-given-functions-variable-values)
    - [Setting global variables](#setting-global-variables)
- [Breakpoints](#breakpoints)
    - [Break on line number](#break-on-line-number)
    - [Break on function name](#break-on-function-name)
    - [Break on source file function name](#break-on-source-file-function-name)
    - [Continue the program after breakpoint](#continue-the-program-after-breakpoint)
    - [View all set breakpoints](#view-all-set-breakpoints)
    - [Delete a breakpoint](#delete-a-breakpoint)
    - [Single step line by line](#single-step-line-by-line)
    - [Step to line number](#step-to-line-number)
    - [Step into a function](#step-into-a-function)
- [Viewing call stack](#viewing-call-stack)
    

- [External References](#external-references)

### Compiler options
To use the gdb debugger the `-g` flag should be set at program compile time. Debugging information is then built into the executable file.

```bash
$ gcc -g -o main.exe main.c
```

### Starting and quitting the debugger

Starting the debugger using the command-line interface.
```bash
$ gdb main.exe
```

Type c to continue, then you are presented with the gdb prompt (gdb) as shown below.

```bash
...
Reading symbols from d...
(gdb)
```

Use `-q` to start in quiet mode.
```bash
$ gdb -q main.exe
Reading symbols from main.exe...
(gdb)
```

Quitting a running program.
```bash
(gdb) quit // alternatively q 
```
Quitting the Debugger.
If a program is not running.
```bash
(gdb) quit // alternatively q 
```

### Viewing help documentation
View gdb documentation.
```bash
(gdb) help // alternatively h
```
View help documentation on breakpoint commands.
```bash
(gdb) help breakpoints // alternatively h breakpoints
```

### Running the program in the debugger
```bash
(gdb) run // alternatively r
```

### Show program argument list
```bash
(gdb) show args
```

### info command

#### View info on source file
Use the `info` command to view information about the program.

```bash
(gdb) info source // alternatively use: i source
```

#### View all local variables and values
```bash
(gdb) info locals
```

### list command

List lines of code using the `list` command.

#### List all lines of code of the main function
```bash
(gdb) list // alternatively l
```
Press `enter` key to scroll through all lines.
#### List lines of code of the main function
```bash
(gdb) list 9 // alternatively l 9
```

#### List lines of code around a given line number of main.c
List 5 lines before and 5 lines after line 9.
```bash
(gdb) list 9 // alternatively l 9
```

#### List next 10 lines of code
```bash
(gdb) list + // alternatively l +
```
#### List previous 10 lines of code
```bash
(gdb) list - // alternatively l -
```
#### List previous x number of lines of code
```bash
(gdb) list -5 // alternatively l -5
```

#### List next x number of lines of code
```bash
(gdb) list +5 // alternatively l +5
```

#### List in range lines of code
```bash
(gdb) list 10,15 // alternatively l 10,15
```

#### List lines of code in a given function
```bash
(gdb) list function-name // alternatively l function-name
```

### print command
View variable values using the `print` command.

#### View variable values
View a main function variable value in **decimal**, if stepped into a function.
```bash
(gdb) print variable-name // p variable-name
```
View a int variable named `x` in **decimal**.
```bash
(gdb) p x
$1 = 42424242
```

View a main function variable value in **binary**, if stepped into a function.
```bash
(gdb) print/t variable-name // p/t variable-name
```
View a int variable named `x` in **binary**. Any leading zeros are removed.
```bash
(gdb) p /t x
$4 = 10100001110101011110110010
```


View a main function variable value in **hexadecimal**, if stepped into a function.
```bash
(gdb) print/x variable-name // p/x variable-name
```
View a int variable named `x` in **hexadecimal**.
```bash
(gdb) p /x x
$3 = 0x28757b2
```


View a main function variable address.
```bash
(gdb) print &variable-name // p &variable-name
(gdb) print &variable-name+1 // view next memory location using pointer arithmetic
```
View given name function variable value
```bash
(gdb) print function-name::variable-name // p function-name::variable-name
```


#### View structs and union
Use the print command followed by the name of the struct/union. Use `->` operator to view members.
```bash
(gdb) print myCompany
$1 = {{id = 0, age = 0, wage = 0}, numberOfEmployees = 7, CEO = {id = 1, age = 32, wage = 55000}}
(gdb) print myCompany->age
$2 = 0
(gdb) print myCompany->CEO
$3 = {id = 1, age = 32, wage = 55000}
(gdb) print myCompany->CEO->age
$4 = 32
```
### Viewing Memory Contents
To examine the contents of memory directly (actual bit patterns), you can use the x command followed by the memory address. For example:
```bash
(gdb) x/bt 0x7ffffcc40 // alt: x/tb 0x7ffffcc40
0x7ffffcc40:    01000101
```
This command displays the 4 bytes from the specified low order bytes starting address in binary format.
To display the 4bytes used to store a integer variable named `x` use:-
```bash
(gdb) x/4bt &x // The 4 here represents display 4 bytes
0x7fffffffdfac:	10110010	01010111	10000111	00000010
```
**Note:** Low order byte displayed first, need to reverse byte order for actual **binary** equivalent of int x.

To view in **binary** the four bytes move up the memory addresses.
```bash
(gdb) x/tb 0x7fffffffdfac // Starting point
0x7fffffffdfac:	10110010
(gdb) x/tb 0x7fffffffdfad // next address
0x7fffffffdfad:	01010111
(gdb) x/tb 0x7fffffffdfae // next address
0x7fffffffdfae:	10000111
(gdb) x/tb 0x7fffffffdfaf
0x7fffffffdfaf:	00000010 // last address
```
Actual binary value is: 00000010100001110101011110110010


To view in **hexadecimal** the four bytes move up the memory addresses.

**Note:** Low order byte displayed first, need to reverse byte order for actual **hexadecimal** equivalent of int x.

```bash
(gdb) x/tx 0x7fffffffdfac  // Starting point
0x7fffffffdfac:	0xb2
(gdb) x/tx 0x7fffffffdfad
0x7fffffffdfad:	0x57
(gdb) x/tx 0x7fffffffdfae
0x7fffffffdfae:	0x87
(gdb) x/tx 0x7fffffffdfaf
0x7fffffffdfaf:	0x02
```
Actual hexadecimal value is: 0x028757b2


### Setting variable values

Set a variables value using the `set` command.

#### Setting main function variable values
```bash
(gdb) set var i = i * 2
```
Set a variable to a previously printed variable.
```bash
(gdb) print i
$1 = 5
(gdb) set var j = $1 // j = 5
```

#### Setting a given functions variable values
The function must be active at time.
```bash
(gdb) set var function-name::j = 5 // function-name j = 5
```

#### Setting global variables
```bash
(gdb) set var main.c::global-variable-name = 5
```

#### Setting array elements
After hitting a breakpoint. Set the values of an initialised array. Any undefined array elements are set to `0`.

```bash
(gdb) set var array = {100, 200}
(gdb) print array
$3 = {100, 200, 0, 0, 0}
```
### Breakpoints
Before running the program, use the `break` command to set breakpoint to suspend the program at a given line. Use `list` command to view the lines of code first if needed.

#### Break on line number
During program suspension further break points can be added.
```bash
(gdb) break 4 // alternatively b 4
Breakpoint 1 at 0x10040108d: file main.c, line 8.
```

#### Break on function name
```bash
(gdb) break main // alternatively b main
Breakpoint 1 at 0x10040108d: file main.c, line 8.
```

#### Break on source file function name
Given source file `foo.c` contains function named `foo`.
```bash
(gdb) break foo.c:foo // alternatively b foo.c:foo
```

#### Continue the program after breakpoint
Run the program using `run` command, program will suspend at set breakpoint. Use `continue` command to resume program execution until second breakpoint (if exists)
```bash
(gdb) continue // alternatively c
```

#### View all set breakpoints
Use the `info` command to view any set breakpoints.
```bash
(gdb) info break // // alternatively use: i break
```

#### Delete a breakpoint
Use the `clear` command to delete a breakpoint at a line or function name.
```bash
(gdb) clear 8 // line 8 breakpoint deleted
(gdb) clear main // clear main function break point
```

#### Single step line by line
After a breakpoint has been hit, single step using the `step` command.
```bash
(gdb) step // alternatively s
```

#### Step to line number

```bash
(gdb) step 15 // alternatively s 15
```

#### Step into a function
By default gdb with step into any non system defined functions.
Use `next` command to **not** step into a function but skip o ver the function.

### Viewing call stack
Stack trace is a call stack which show the hierarchy of function calls.

View call stack using the `backtrace` or `bt` command.

- Set a breakpoint
- Run the program, 
- At breakpoint view call stack using `bt` command

```bash
(gdb) bt
```
Navigate the call stack frame using `up`, `down`, `frame` and `info args` commands


## External References
- [udemy.com | Advanced C programming course | Debugging with gdb part1](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17962238#overview)
- [udemy.com | Advanced C programming course | Debugging with gdb part2](https://www.udemy.com/course/advanced-c-programming-course/learn/lecture/17962242#overview)
- [GDB: The GNU Project Debugger Documentation](https://www.gnu.org/software/gdb/documentation/)
- [Online Converter](https://www.rapidtables.com/convert/number/decimal-to-hex.html)

[Back to top](#table-of-contents)
