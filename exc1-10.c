#include <stdio.h>

int main()
{
    int c, blankNum;

    blankNum = 0;

    while ((c = getchar()) != EOF)
    {

        if (c == '\\')
        {
            putchar('\\');
        }
        if (c == '\b')
        {

            putchar('\\');
            putchar('b');
        }
        if (c == ' ')
        {
            putchar('\\');
            putchar('t');
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}