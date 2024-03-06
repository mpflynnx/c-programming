## Type casting

Sometimes in programming a variable type may need to be converted  or cast. 

Casting `a` int variable type to a double type.
```c
int a = 5;
(double) a; // 5.0
```

This is particularly true when using integers with division operators. For example, 5 / 2 is 2.5, but a `c` program would return the value 2. To get the correct answer just one of the integers needs to be cast into a double type. A double divided by an integer returns a double. An integer divided by a double returns a double.

```c
int a = 5;
int b = 2;

double c = (double) a / b;

printf("%d / %d = %f\n", a, b, c);
```

**Output**
```bash
5 / 2 = 2.500000
```

Casting takes precedence over anything else.
For example, in the code below, `a` is cased to a double type before the division operator `/` is applied in the expression.

```c
(double) a / b; // 5.0 / 2 = 2.5
```