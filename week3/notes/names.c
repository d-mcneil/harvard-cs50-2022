#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"bill", "charlie", "fred", "george", "ron", "ginny", "percy"};
    // string search_name = "harry";  intitializing variable and then using == to compare does work, while using == to compare the string without defining a variable returns error
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i],"ron") == 0) // what he did in the video
        // if (!strcmp(names[i],"harry")) this works because of truthy/falsey, but is arguably not as clean because it is such a small detail and hides meaning a bit
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}