#include <stdio.h>

// get char one by one
// find its lowercase equivelant
// put c that equivalent

int main()
{
    int current;

    while ((current = getchar()) != EOF)
    {
        if (current >= 'A' && current <= 'Z') // Correct range for uppercase letters
        {
            char lower = current + ('a' - 'A'); // Convert to lowercase
            putchar(lower);
        }
        else
        {
            putchar(current); // Print non-uppercase characters as they are
        }
    }
    return 0;
}

int faster()
{
    int current;
    char lower;

    while ((current = getchar()) != EOF)
    {
        putchar((current >= 'A' && current <= 'Z') ? (current = current + ('a' - 'A')) : current);
    }
    return 0;
}

// condition ? expression_if_true : expression_if_false;
