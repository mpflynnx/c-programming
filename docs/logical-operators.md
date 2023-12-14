## Logical operators

Logical operators sometime called boolean operators allow us to combine boolean into new boolean values. For example to check two values are true. Compound conditional expressions.

### And operator

`&&` is the `and` logical operator. Checks that both conditions on either side are true.

```c
if (height > 150 && weight > 50)
    printf("Good!\n");
```

height must be greater than 150 and weight must be greater than 50 for "Good!" to print to screen.

If either height operand or weight operand is false, then the whole expression is false.

### Or operator

`||` is the or operator. Checks either operands on either side can be true. Both, can be true or only one is needed to be true to return true. For expression to return false both operands must be false.

```c
if (height > 150 || weight > 50)
  printf("Good!\n");
```

Either height can be greater than 150 or weight must be greater than 50 for "Good!" to print to screen.

### Not operator

`!` not operator. Takes a true and makes it false. Takes a false and makes to true. Invertor.

```c
if (! (height > 150))
    printf("Not good!\n");
else
    printf("Good!\n");
```

Prints "Not good" if height not greater than 150.

Must use brackets () around height > 150 comparison so that this is done first. 

Use not operator to make code more readable.

### Operator precedence

Without using brackets around a comparison, the default [operator precedence](https://en.cppreference.com/w/c/language/operator_precedence) is used.

`!` has precedence over `<`

It is best practice to use brackets around comparisons.