#include <stdio.h>

int main()
{
    int c, blankNum;

    blankNum = 0;

    while ((c = getchar()) != EOF)
    {

        if (c == ' ')
        {
            ++blankNum;
            if (blankNum == 1)
            {
                putchar(c);
            }
        }

        else
        {
            blankNum = 0;
            putchar(c);
        }
    }
    return 0;
}