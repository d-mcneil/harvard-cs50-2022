#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // char *s = get_string("s: ");
    // char *t = s;
    // t[0] = toupper(t[0]);
    // printf("%s\n", s);
    // printf("%s\n", t);
    // // BOTH s AND t are capitalized
    // // this is because s and t point to the same address

    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
        // sometimes malloc can fail because there isnt ram available
    }
    // // old school way of copying string
    // for (int = 0; n = strln(s) + 1; i < n; i++)
    // {
    //     t[i] = s[i];
    // }
    strcpy(t,s);
    // first argument is destination in memory
    // second argument is source
    if (strlen(t))
    {
       t[0] = toupper(t[0]);
    }
    printf("%s\n", s);
    printf("%s\n", t);

    free(t);

}