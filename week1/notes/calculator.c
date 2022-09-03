#include <cs50.h>   // helper functions written by cs50
#include <stdio.h>  // standard input and output

int main(void)
{
    // int x = get_int("x: ");     the commented out portions dont
                                //work because of integer overflow
    long x = get_long("x: ");
    // int y = get_int("y: ");
    long y = get_long("y: ");
    // int z = x + y;
    long z = x + y;
    // printf("%i\n", z);
    printf("%li\n", z);
}