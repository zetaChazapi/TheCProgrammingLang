#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char hex[1000];
int htoi(char s[]);
int i, dec;

int main()
{
}

int htoi(char hex[])
{

    dec = 0;
    int length = strlen(hex);
    int base = 1;

    for (int i = length - 1; i >= 0; --i) // Start from the end of the string
    {
        // if digit is 0-9
        if (isdigit(hex[i]))
        {
            dec += (hex[i] - '0') * base;
        }
        // if digit is uppercase
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 'A' + 10) * base;
        }
        // if digit is lowercase
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec += (hex[i] - 'a' + 10) * base;
        }
        else
        {
            printf("not valid input");
            return 0;
        }
        base *= 16;
    }
    return dec;
}
