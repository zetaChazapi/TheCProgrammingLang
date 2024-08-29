#include <stdio.h>

int main()
{
    double count;

    count = 0;

    // Count characters until EOF
    for (count = 0; getchar() != EOF; ++count)
        ;

    // Print the count of characters
    printf("%.0f\n", count);

    return 0; // Indicate successful execution
}
