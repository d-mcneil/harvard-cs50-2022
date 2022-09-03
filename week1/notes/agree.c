#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user to agree to something
    char response = get_char("Do you agree? ");

    if (response == 'y' || response == 'Y')
    {
        printf("Agreed\n");
    }

    else if (response == 'n' || response == 'N')
    {
        printf("Not agreed\n");
    }
}