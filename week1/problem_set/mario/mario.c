#include <stdio.h>
#include <cs50.h>
void question_mark(int number_of_question_marks);
void big_block(int rows, int columns);

int main(void)
{
    int width;
    do
    {
        width = get_int("Width of block: ");
    }
    while (width < 1);

    int height;
    do
    {
        height = get_int("Height of block: ");
    }
    while (height < 1);
    big_block(height, width);


    int n;
    do
    {
        n = get_int("Width of block: ");
    }
    while (n < 1);
    question_mark(n);


}



void question_mark(int number_of_question_marks)
{
    for (int i = 0; i < number_of_question_marks; i++)
    {
        printf("?");
    }
    printf("\n");
}

void big_block(int rows, int columns)
{
    // for each row
    for (int i = 0; i < rows; i++)
    {
        // for each column
        for (int j = 0; j < columns; j++)
        {
            // print a brick
            printf("#");
        }
    printf("\n");
    }
}