#include <cs50.h>   // get_string was written by cs50
#include <stdio.h>  // standard input and output

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer); //printf is taking 2 inputs
                              //"hello, %sn"    and    answer

    int counter = 0;
    counter = counter + 1;
    counter += 1; // syntactic sugar
    counter++; // increment by 1
    counter--; // increment down by 1
    printf("%i\n", counter);

    int x = 2;
    int y = 3;


    if (x < y)
    {
        printf("x is less than y\n");
    }



    if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is not less than y\n");
    }



    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }






}