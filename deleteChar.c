#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "hello world";
    char s2[] = "ld";

    squeeze(s1, s2);
    printf("Resulting string: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int found;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        found = 0;
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}