#include <stdio.h>

// get char one by one
// find its lowercase equivelant
// put c that equivalent

int main()
{
    int current;

    while ((current = getchar()) != EOF)
    {
        if (current >= 'A' && current <= 'B')
        {
            char lower = current + ('a' - 'A');
            putchar(lower);
        }
        else
        {
            putchar(current);
        }
    }
}