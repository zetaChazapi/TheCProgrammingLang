#include <stdio.h>

// n that older version of C, it was common to omit the return type of main,
// and it would default to int. However, in modern C, the compiler requires
// you to explicitly declare the return type of functions, including main.

int main()
{
    printf("hello, world\n");
    return 0;
}