#include <cs50.h>
#include <stdio.h>
int get_check_sum(long cc_number);
int get_first_number(long cc_number);
void check_if_valid (int check_sum, int first_number);

// 4003 6000 0000 0014   test numbers
// 5555 5555 5555 4444
// 4222 2222 2222 2
// 4012 8888 8888 1881
// 3782 8224 6310 005

int main(void)
{
    long user_cc_number;
    do
    {
        user_cc_number = get_long("Number: ");
    }
    while (
        ((4000000000000000 > user_cc_number) || (user_cc_number > 4999999999999999)) && //visa 16 digit
        ((4000000000000 > user_cc_number) || (user_cc_number > 4999999999999)) &&       //visa 13 digit
        ((5100000000000000 > user_cc_number) || (user_cc_number > 5599999999999999)) && //mc 16 digit
        ((340000000000000 > user_cc_number) || (user_cc_number > 349999999999999)) &&   //amex 34 start
        ((370000000000000 > user_cc_number) || (user_cc_number > 379999999999999))      //amex 37 start
    );
    int user_cc_number_check_sum = get_check_sum(user_cc_number);
    int user_cc_first_number = get_first_number(user_cc_number);
    check_if_valid(user_cc_number_check_sum, user_cc_first_number);
}

int get_check_sum(long cc_number)
{
    int first_sum = 0;
    int second_sum = 0;
    for (int i = 1; cc_number >= 1; i++)
    {
        if (i % 2 == 0)
        {
            int temporary = 2*(cc_number % 10);
            for (int j = 1; temporary >= 1; j++)
            {
                first_sum += (temporary % 10);
                temporary /= 10;
            }
            cc_number /= 10;
        }
        else
        {
            second_sum += (cc_number % 10);
            cc_number /= 10;
        }
    }
    return first_sum + second_sum;
}

int get_first_number(long cc_number)
{
    for (int i = 1; cc_number >= 10; i++)
    {
        cc_number /= 10;
    }
    return cc_number;
}

void check_if_valid (int check_sum, int first_number)
{
    if (check_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (first_number == 5)
    {
        printf("MASTERCARD\n");
    }
    else if (first_number == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("AMEX\n");
    }
}