#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
char longestThanEighty[MAXLINE];
void reverse(char s[], int p, int r);
int x, p, r;

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("\nLongest line and its length:\n");
        printf("%s%d\n", longest, max);
        printf("%s\n", longestThanEighty);
    }

    char testString[] = "Hello, World!";
    printf("Original string: %s\n", testString);
    reverse(testString, 0, strlen(testString) - 1);
    printf("Reversed string: %s\n", testString);

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    if (i >= 80)
    {
        copy(longestThanEighty, s); // Copy the line to longestThanEighty
    }
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

void reverse(char s[], int p, int r)
{
    if (p < r)
    {
        x = s[p];
        s[p] = s[r];
        s[r] = x;
        reverse(s, p + 1, r - 1);
    }
}