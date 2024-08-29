#include <stdio.h>

int convert(int fahr);

// always upper case constants
#define LOWER 0   // lower limit
#define UPPER 300 // upper limit
#define STEP 20   // step size

int convert(int fahr)
{
    printf("%6d %12.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}

int main()
{
    int fahr, val;

    printf("Farenheit to Celsius\n");

    for (val = LOWER; val <= UPPER; val = val + STEP)
    {
        convert(val);
    }
    return 0;
}