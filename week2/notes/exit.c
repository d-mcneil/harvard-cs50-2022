#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("incorrect number of command line arguments: 2 required\n");
        return 1;  // program was unsuccessful
    }
    printf("hello %s\n", argv[1]);
    return 0; // this is already done by default
}



wget https://cdn.cs50.net/2021/fall/psets/2/readability.zip