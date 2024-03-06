#include <stdio.h>

void add_one(int *array, int length);

int main()
{

    int a[] = {1,2,3,4,5,6,7,8,9,10};

    add_one(a + 5, 5);

    for (int i = 0; i < 10; i++)
        printf("a[%d]=%d\n", i, a[i]);

	return 0;

}
