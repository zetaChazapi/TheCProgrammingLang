#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// get net intiger from input and store in *pn

int getint(int *pn)
{

    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c = EOF)
    {
        ungetch(c);
    }
    return c;
}