## printf placeholder fields

While running the [Meters to Feet conversion program](/docs/meters-to-feet-conversion.md). Given the inputs provided below the output table starts to look messy.

```bash
Enter start (m): 1
Enter step (m): 2
Enter stop (m): 13

Meters     Feet
*******************
1.000000 3.280840
3.000000 9.842520
5.000000 16.404200
7.000000 22.965880
9.000000 29.527560
11.000000 36.089240
13.000000 42.650920
```

I can improve this by using additional flags with the placeholder `%f` in this example to modify the output format.

### Limit decimal places

Here the number of decimal places would be limited to 2.
```c
"%.2f"
```
Using this in our program the output would be:

```bash
Meters     Feet
*******************
1.00 3.28
3.00 9.84
5.00 16.40
7.00 22.97
9.00 29.53
11.00 36.09
13.00 42.65
```

Here are some other popular [flags](https://en.wikipedia.org/wiki/Printf#Flags_field) to use with placeholders:

- %3d: prints an integer in a field of width 3.
- %06d: prints an integer in a field of width 6, with leading zeros.


I will choose a field width of 10.  

```c
"%10.2f"
```
Using this in our program the output would be:

```bash
Meters     Feet
*******************
      1.00       3.28
      3.00       9.84
      5.00      16.40
      7.00      22.97
      9.00      29.53
     11.00      36.09
     13.00      42.65
```

The default is to right-align the output. We can left-align the output using `-`.

```c
"%-10.2f"
```
Using this in our program the output would be:

```bash
Meters     Feet
*******************
1.00       3.28      
3.00       9.84      
5.00       16.40     
7.00       22.97     
9.00       29.53     
11.00      36.09     
13.00      42.65 
```