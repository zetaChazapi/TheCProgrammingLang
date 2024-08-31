#include <stdio.h>

int bitCount(unsigned x);
int bitCountFaster(unsigned x);

int bitCount(unsigned x)
{
    int b; // Variable to store the count of '1' bits

    for (b = 0; x != 0; x >>= 1) // Loop until x becomes 0
    {
        if (x & 01) // Check if the least significant bit is '1'
        {
            b++; // Increment the count of the bit is '1'
        }
    }
    return b; // Return the total count of '1' bits
}

int bitCountFaster(unsigned x)
{
    int b; // Variable to store the count of '1' bits

    for (b = 0; x != 0; x &= (x - 1)) // Loop until x becomes 0
    {
        b++; // Increment the count for each cleared bit
    }
    return b; // Return the total count of '1' bits
}
