#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[3];
    for (int i = 0; i < 3; i++){
        printf("%i\n", scores[i])
    }
    // logical bug - didn't include the actual scores!
    // when you don't initialize values, the computer could put other values from past computing instead
    // GARBAGE VALUES
}