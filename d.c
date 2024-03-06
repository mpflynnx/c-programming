// https://www.youtube.com/watch?v=1MtzsZmcVFE&list=PLlRFEj9H3Oj5NbaFb1b2n8lib01uNPWLa&index=16&t=2s
// @ time 24.30

#include <stdio.h>
#include <string.h>

union sample {
    int i;
    char ca[4];
    float f;
};

int main()
{

    union sample u;
    
    u.i = 42;
    printf("%08x %f %s\n", u.i, u.f, u.ca);
    
    strcpy(u.ca, "Abc");
    printf("%08x %f %s\n", u.i, u.f, u.ca);
    
    u.f = 1.0/3.0;
    printf("%08x %f %s\n", u.i, u.f, u.ca);

	return 0;

}
