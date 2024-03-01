#include <stdio.h>

typedef struct
{
    double x;
    double y;
    double z;
}Point3d;

Point3d getZeroPoint()
{
    // We can create a variable and return the variable (we'll improve this below)
    // Point3d temp = { 0.0, 0.0, 0.0 };
    // return temp;
    // return (Point3d){0.0, 0.0, 0.0};
    return (Point3d){};
}

int main()
{
    Point3d zero = getZeroPoint();

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        printf("The point is zero\n");
    else
        printf("The point is not zero\n");

    return 0;
}