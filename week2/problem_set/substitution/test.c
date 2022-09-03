#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // char abcdefg[9] = "abcdefg";
    // string nothing = "z";
    // strncat(nothing, abcdefg, 1);
    // printf("%s", nothing);
    char str[10] = "";
    char ch[10] = "Geeksabc";

    strncat(str, ch, 10);
    printf("%s\n", str);
    printf("%c\n", str[0]);
    printf("%c\n", str[1]);
    printf("%c\n", str[2]);
    printf("%c\n", str[3]);
    printf("%c\n", str[4]);
    printf("%c\n", str[5]);
    printf("%c\n", str[6]);
    printf("%c\n", str[7]);
    printf("%i\n", str[8]);
    printf("%i\n", str[9]);
    // printf("%c\n", str[10]);
    // printf("%c\n", str[11]);
}