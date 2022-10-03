#include <cs50.h>
#include <stdio.h>

int main(void)
{
 int n = 50;
 printf("%i\n", n);

 int *z = &n;
 printf("%p\n", z);
 printf("%p\n", &n); // produces the same address as printing p

printf("%i\n", *z); // prints the value at pointer p (50)

 // p is a pointer
 // it points to the location of an integer
 // i.e., it stores the location of an interger
 // the asterisk means it's an address
 // &n means the address of n

// using cs50 header file
string s = "HI!";
printf("%s\n", s);

// not using cs50 header file
char *t = "HI!";
printf("%s\n", t);

char c = s[0];
char *q = &c;
printf("%p\n",q);
// c is a copy of the first character in s
// q points to c, not s
printf("%p\n", s);
// so this address is different than the previous print statement

printf("\n");

char *p = &s[0];
printf("%p\n", p);
// the address of the first character in s
printf("%p\n", s);
// these 2 statements print out the same address
// because string s is simply a pointer to the first character in the string

printf("\n");

printf("%p\n", s);
printf("%p\n", &s[0]); // prints same address as previous line
printf("%p\n", &s[1]);
printf("%p\n", &s[2]);
printf("%p\n", &s[3]);


printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
printf("%c\n", s[3]); // null character


printf("%c\n", *s); // H
printf("%c\n", *(s+1)); // I   - pointer arithmetic
printf("%c\n", *(s+2)); // !

int numbers[] = {4,6,8,2,7,5,0};
printf("%i\n", *numbers);
printf("%i\n", *(numbers+1));
printf("%i\n", *(numbers+2));
printf("%i\n", *(numbers+3));
printf("%i\n", *(numbers+4));

}