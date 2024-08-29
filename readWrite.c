#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

// end of file = EOF = -1
// putchar = prints contents of the integer c as a char
// getchar = next characher from input