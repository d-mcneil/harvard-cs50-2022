#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>  // can include this for the uppercase checkand conversion

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if (s[i] >= 'a' && s[i] <= 'z')
        if (islower(s[i]))
        {
            // printf("%c", s[i]-32);
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    // can actually just do this because of how toupper works
    string t = get_string("Before: ");
    printf("After:  ");
    for (int j = 0, m = strlen(t); j < m; j++)
    {
        printf("%c", toupper(t[j]));
    }
    printf("\n");
}