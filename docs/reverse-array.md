## Reverse an Array

- [Coded Solution](/code/reverse-array-example/d.c)

For odd length arrays the middle element stays the same.
- Swap first element with last element
- Swap second element with second to last element
- Swap third element with third last element
- ..
- ..
- Until one less than middle element reached

For even length arrays all elements need to be swapped.

- Swap first element with last element
- Swap second element with second to last element
- Swap third element with third last element
- ..
- ..
- Until one less than middle element reached.

Find middle of array using: -

array size divided by 2

Use a int temp variable to help swap the values.

given array [1,2,3,4,5,6,7,8,9]

size of array is 9;

middle element is half of size(9) 
9 / 2 = 4 (due integer division float value omitted)
therefore loop while < 4  ( i.e elements 0 to 3) 4 loops

loop1
copy value at element 0 to temp, temp = 1
overwrite element 0 with value at element 9
overwrite element 9 with value of temp 1.
9,2,3,4,5,6,7,8,1 after 1st loop

loop2
copy value at element 1 to temp, temp = 2
overwrite element 1 with value at element 8
overwrite element 8 with value of temp 2.
9,8,3,4,5,6,7,2,1 after 2nd loop

loop3
copy value at element 2 to temp, temp = 3
overwrite element 2 with value at element 7
overwrite element 7 with value of temp 3.
9,8,7,4,5,6,3,2,1 after 3rd loop

loop4
copy value at element 3 to temp, temp = 4
overwrite element 3 with value at element 6
overwrite element 6 with value of temp 4.
9,8,7,6,5,4,3,2,1 after 4th loop

The array is reversed.

**Remember** an array (e.g. int arr[5]) decays into a pointer (int*).

Because a C-style arrays decays to a pointer when evaluated, when a C-style array is subscripted, the subscript is actually operating on the decayed array pointer:

## References
- [Portfolio courses](https://www.youtube.com/watch?v=7EfA0cwZGC0&t=329s)
- [sizeof operator](https://en.cppreference.com/w/c/language/sizeof)
- [learncpp.com | Introduction to C-style arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/)
- [learncpp.com | C-style array decay](https://www.learncpp.com/cpp-tutorial/c-style-array-decay/)