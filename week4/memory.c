// program deliberately created with memory errors
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72; // forgot about zero indexing, will cause error in future
    x[2] = 73;
    x[3] = 33; // error 1 - touching memory that I shouldn't be touching
    // buffer overlow - going beyond bounds of chunk of memory

    // error 2 - not freeing memory after allocating it

    // valgrind - program designed to find memory related bugs in code
    // valgrind ./program_name
    // error 1 - invalid write
    // error 2 - memory leak
}