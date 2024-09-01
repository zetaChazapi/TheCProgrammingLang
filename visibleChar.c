#include <stdio.h>
int escape(char s[], char t[]);

int main()
{
    return 0;
}

int escape(char s[], char t[])
{
    int current, i;

    while ((current = getchar()) != EOF)
    {
        for (i = 0; i <= len(s); i++)
        {
            switch (current)
            {
            case ' ':
                t[i] = '\t';
            case '\n':
                t[i] = '\n';
            default:
                t[i] = current;
            }
        }
    }
}