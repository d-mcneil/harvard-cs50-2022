#include <stdio.h>
#include <cs50.h>
void print_brick(void);
void print_space(int spaces);
void print_block(int height);

int main(void)
{

    int block_height;
    do
    {
        block_height = get_int("Enter the height of the block from 1-8: ");
    }
    while (block_height < 1 || block_height > 8);
    print_block(block_height);
}

void print_brick(void)
{
    printf("#");
}

void print_space(int spaces)
{
    for (int h = 0; h < spaces; h++)
    {
    printf(" ");
    }
}

void print_block(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j >= 0; j--)
        {
            if (j <= i)
            {
                print_brick();
            }
            else
            {
                print_space(1);
            }
        }
        print_space(2);
        for (int k = 0; k < height; k++)
        {
            if (k <= i)
            {
                print_brick();
            }
            else
            {
                print_space(1);
            }
        }
        printf("\n");
    }
}