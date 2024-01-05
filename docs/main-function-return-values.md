## Main function return values

The return value from the main function is needed to inform the bash shell that executed the program the exit status of the program.

We have used `return 0`, as the return statement for our programs. These is the recommended default.

```c
int main(void)
{

    ... 
    
    return 0;
}
```

Using the bash command below, we can retrieve the last run programs return status.

```bash
echo $?
```

A return status of `0` is successful, any other value such as `return 1;` could indicate some sort of error with the programs execution.

When running a `c` program from a bash script, the script can use the return status to decide on it's next action. A return status of 1 from a program, may suggest the bash script should terminate and exit, rather than continue. 