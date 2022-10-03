#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    // passing in copies of a and b, not actually using x and y
    printf("x is %i, y is %i\n", x, y);
}

// different parts of computer's memory are used for different purposes
// when you compile a program, all of that info is stored at the beginning of the memory
// below that global variables are stored
// heap - malloc
// stack - local variables in a function
// when you use lots of memory, functions (stack) or malloc (heap)
// you can run out of space between them, they overflow each other
// (stack overflow)


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// if you want one function to affect the value of a variable somewhere else, you have to pass in pointers