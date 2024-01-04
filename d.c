#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
} Student;

void age_student(Student *s);

int main(void)
{
    Student *s1; //pointer to a Student type

    s1 = calloc(1, sizeof(Student));

    printf("Age: %d\n", (*s1).age );

    age_student(s1);

    printf("Age: %d\n", (*s1).age );

    free(s1);

    return 0;
}

void age_student(Student *s)
{
    s->age += 1;
}