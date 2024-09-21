#include <stdio.h>

// p = &c ------ assigns the adress of c to variable p
// * = accesses the object that the pointer points to

int x = 1, y = 2, z[10];
int *ip;
void swap(int *px, int *py);

ip = &x;    // ip pointer to adress of x
y = *ip;    // y = the contents of pointer ip = 1
*ip = 0;    // x is now 0
ip = &z[0]; // ip points to adress of z[0]

// statement "double *dp, atof(char *) = the pointer dp
// points to a double and the atof function takes a char pointer

void swap(int *px, int *py)
{
    int temp;
    *px = *py;
    *py = temp;
}