#include <stdio.h>

int main()
{
    int farh, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    farh = lower;
    while (farh <= upper)
    {
        // %d is a int placeholder
        // \t tab between values

        // %3d and %6d three digits wide and the six digits wide

        celsius = (5.0 / 9.0) * (farh - 32.0);
        printf("%3d.0f %6d.1f\n", farh, celsius);

        farh = farh + step;
    }
}