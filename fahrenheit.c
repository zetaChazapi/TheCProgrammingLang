#include <stdio.h>

int main()
{
    printf("Fahrenheit to Celsius\n");

    float farh, celsius;
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
        //%3f and %6f without d because it is not int anymore

        celsius = (5.0 / 9.0) * (farh - 32.0);
        printf("%6.0f %12.1f\n", farh, celsius);

        farh = farh + step;
    }

    printf("\nCelsius to Fahrenheit\n");

    float farh2, celsius2;
    int lower2, upper2, step2;

    lower2 = 0;
    upper2 = 300;
    step2 = 20;

    farh2 = lower2;

    while (farh2 <= upper2)
    {
        // %d is a int placeholder
        // \t tab between values

        // %3d and %6d three digits wide and the six digits wide
        //%3f and %6f without d because it is not int anymore

        celsius2 = (5.0 / 9.0) * (farh2 - 32.0);
        printf("%6.1f %12.0f\n", celsius2, farh2);

        farh2 = farh2 + step2;
    }
}
// %d = decimal number
// %6d = at least 6 digit wide decimal number
// %f = float number
// %6f = at least 6 digit wide float number
// %.2f = float with 2 characters after decimal point
// %6.2f = at least 6 digit wide float number with 2 characters after decimal point
// %o = octal
// %x = hexadecimal
// %c = characters
// %s = string
// %% = %