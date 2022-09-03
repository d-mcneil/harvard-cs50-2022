#include <cs50.h>
#include <stdio.h>

void meow(void); // function abstracted away at bottom
// this line is a breadcrumb to let c know that this
// function will be defined later
void meow_loop(int n);


int main(void)
{
    int i = 0;
    while (i < 3)
    {
        meow();
        i++;
    }

    printf("\n");

    for (int x = 0; x < 3; x++)
    {
        meow();
    }

    printf("\n");

    meow_loop(get_int("the cat will meow this many times: "));
}















void meow(void)
{
    printf("meow\n");
}

void meow_loop(int n)
{
    for (int x = 0; x < n; x++)
    {
        printf("meow\n");
    }
}
