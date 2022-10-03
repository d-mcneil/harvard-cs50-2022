#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // int i = get_int("i: ");
    // int j = get_int("j: ");

    // if (i==j)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // these 2 variables point to different location
    if (s == t) // even if these strings are identical, it is still the else condition that runs
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    if (!strcmp(s,t)) // this is the reliable way to compare 2 strings
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    printf("%s\n", s);
    printf("%s\n", t);

    printf("%p\n", s); // two different addresses for strings that look the same
    printf("%p\n", t);

}