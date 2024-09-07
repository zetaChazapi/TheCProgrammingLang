#include <stdio.h>

#define swap(t, x, y) \
    do                \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    } while (0)

int main()
{
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(int, a, b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}

/*Macros are suitable for simple substitutions, constants,
or small code snippets where inline expansion is desired. Functions
are better for encapsulating logic, maintaining code safety,
readability, and debuggability.*/