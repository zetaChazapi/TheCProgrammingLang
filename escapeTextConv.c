#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
    char s[1000];
    char t[2000]; // Ensure `t` is large enough to hold escaped sequences

    printf("Enter text: ");
    escape(s, t);

    printf("Escaped text: %s\n", t);

    return 0;
}

void escape(char s[], char t[])
{
    int current, i = 0, j = 0;

    while ((current = getchar()) != EOF)
    {

        switch (current)
        {
        case ' ':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        default:
            t[j++] = current;
            break;
        }
    }
    t[j] = '\0';
}