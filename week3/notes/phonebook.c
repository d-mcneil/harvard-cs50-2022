#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // string names[] = {"bill", "charlie"};
    // string numbers[] = {"123456789", "1112223333"};
    // for (int i = 0; i < 2; i++)
    // {
    //     if (strcmp(names[i],"harry") == 0)
    //     {
    //         printf("number for %s found, number is: %s\n", names[i], numbers[i]);
    //         return 0;
    //     }
    // }
    // printf("number not found\n");
    // return 1;
    typedef struct
    {
        string name;
        string number;
    }
    person;
    person people[2];
    people[0].name = "bill";
    people[0].number = "1234567890";
    people[1].name = "charlie";
    people[1].number = "1112223333";
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name,"ron") == 0)
        {
            printf("number for %s found, number is: %s\n",people[i].name, people[i].number);
            return 0;
        }
    }
    printf("number not found\n");
    return 1;
}


