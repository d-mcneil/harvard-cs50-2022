// parity is a fancy way to say even or odd
// think par/impar in spanish

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("number: ");

    if (number % 2 == 0)
    {
        printf("%i is even.\n", number);
    }
    else
    {
        printf("%i is odd.\n", number);
    }
}