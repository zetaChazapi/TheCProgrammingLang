#include <stdio.h>

int main()
{
    int c, nl, tab;

    nl = 0;
    tab = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }

        if (c == ' ')
        {
            ++tab;
        }
    }

    printf("%d %d\n", nl, tab);
}