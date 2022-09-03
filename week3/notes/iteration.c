#include <cs50.h>
#include <stdio.h>
void draw(int height);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            // if (j <= i)    the commented part is what i did, and i did j < height instead of j < i + 1
            // {
                printf("#");
            // }
        }
        printf("\n");
    }
}