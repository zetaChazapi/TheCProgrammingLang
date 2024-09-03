#include <stdio.h>

#define MAXLINE 1000

int custom_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould"; // Pattern to search for

int main()
{
    char line[MAXLINE];
    int found = 0;

    while (custom_getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

// Custom line reading function
int custom_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// Function to find the leftmost index of the pattern
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}

int strrindex(char s[], char t[])
{
    int i, j, k;
    int s_len = strlen(s);
    int t_len = strlen(t);

    for (i = s_len - t_len; i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}

// cc main.c getline.c strindex.c if they were all in different files
// a.out is the executable file with all of them together