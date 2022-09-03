# include <cs50.h>
# include <stdio.h>
float discount(float regular_price, float discount);

int main(void)
{
    float regular = get_float("Regular Price: $");
    float sale = regular * .85;

    printf("Sale Price: $%.2f\n", sale);
    printf("\n");


    float sale_price = discount(get_float("Price: $"), get_float("Discount Percentage: "));
    printf("Sale Price: $%.2f\n", sale_price);
}

float discount(float regular_price, float discount)
{
    return regular_price * (1-(discount*.01));
}