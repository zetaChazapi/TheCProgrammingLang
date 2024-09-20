#include <stdio.h>

// p = &c ------ assigns the adress of c to variable p
// * = accesses the object that the pointer points to

int x = 1, y = 2, z[10];
int *ip; //

ip = &x;    // ip pointer to adress of x
y = *ip;    // y = the contents of pointer ip = 1
*ip = 0;    // x is now 0
ip = &z[0]; // ip points to adress of z[0]