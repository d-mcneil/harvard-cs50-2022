# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    int pennies = round(amount * 100);
    // round has to be added because the computer struggles
    // to represent the number correctly
    // example: without it, it represent $4.20 as 419 pennies
    printf("Pennies: %i\n", pennies);

}