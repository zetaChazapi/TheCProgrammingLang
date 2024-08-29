#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main()
{
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n');
            }
            state = OUT;
        }
        else if (state == OUT)
        {
            // When entering a new word
            state = IN;
            ++nw;
            putchar(c); // Print the first character of the new word
        }
        else
        {
            // Continue printing characters inside a word
            putchar(c);
        }
    }

    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
