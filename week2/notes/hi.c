#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i \n", (int) c1, (int) c2, (int) c3);

    string my_string = "HI!";
    printf("%s\n", my_string);
    printf("%c\n", my_string[1]);
    printf("%i\n", my_string[0]);
    printf("%i\n", my_string[1]);
    printf("%i\n", my_string[2]);
    printf("%i\n", my_string[3]); // the nul character
}