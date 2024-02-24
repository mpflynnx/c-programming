#include <stdio.h>

// void reverse_array(int array[], int size); // same as below
void reverse_array(int* arr, int size);
void display_array(int array[], int size);

int main(void){

    // first array to reverse
    int myarray[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(myarray) / sizeof(myarray[0]);
    // int size = 9;
    reverse_array(myarray, size);
    display_array(myarray, size);

    // second array to reverse
    int myarray2[] = {10,9,8,7,6,5,4,3,2,1};
    int size2 = sizeof(myarray2) / sizeof(myarray2[0]);
    reverse_array(myarray2, size2);
    display_array(myarray2, size2);

    return 0;
}

/* 
Reverse an array function
*/
// void reverse_array(int arr[], int size)
// {
//      int temp = 0;
//      printf("middle element index: %d\n", size / 2);

//     for (int i = 0; i < size / 2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[size - i - 1]; // left hand side
//         arr[size - i - 1] = temp; // right hand side
//     }

// }

/* 
Reverse an array function using pointers inside function
*/
void reverse_array(int* arr, int size)
{
    int* start = arr;
    int* end = arr + size - 1;
    while (start < end) {
        // swap elements pointed to by start and end pointers
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Move the pointers towards the center break loop when *start == *end
        start++;
        end--;
    }
}

/*
Display an array function
*/
void display_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %d\n", i, arr[i]);
    }
    printf("\n");   
}
