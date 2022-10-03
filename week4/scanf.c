#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x); // used to get user input
    printf("x: %i\n", x);

    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s); // string is already an address!!
    printf("s: %s\n", s);
    free(s);
    // in this example, the user could only guarantee the program works with maximum 3 characters
}