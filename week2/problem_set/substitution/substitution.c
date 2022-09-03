#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int check_key_valid (string key);
void print_ciphertext(string key, string plaintext);
// I could have done this problem, i think, using ASCII values and calculating the difference between the ascii value and the index value instead of using strchr() to find the difference at the index value
// and it probably would have been wayyyyy easier
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (check_key_valid(key) == 1)  // if the key isn't valid, return 1
    {
        return 1;
    }
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    print_ciphertext(key, plaintext);
    // string ciphertext = print_ciphertext(key, plaintext);   // this commented stuff was when i tried to print ciphertext all at once
    // printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}

int check_key_valid (string key)
{
    int valid_key_length = 26;
    if (strlen(key) != valid_key_length)
    {
        printf("Key must contain %i characters.\n", valid_key_length);
        return 1;
    }
    char temporary_string[valid_key_length + 1];  // used to see if any letters repeat in key
    for (int i = 0; i < valid_key_length; i++)  // checking for nonalphabetical characters and repeat letters in key
    {
        char key_character = key[i];
        char key_character_lower = tolower(key_character);
        if (!isalpha(key_character))
        {
            printf("Key must contain %i alphabetical characters.\n", valid_key_length);
            return 1;
        }
        if (strchr(temporary_string, key_character_lower) == NULL)
        {
            strncat(temporary_string, &key_character_lower, 1);
        }
        else
        {
            printf("Key must contain %i unique, alphabetical characters.\n", valid_key_length);
            return 1;
        }
    }
    return 0;
}

void print_ciphertext(string key, string plaintext)
{
    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int difference_key_minus_alphabet[key_length];
    // char ciphertext[plaintext_length + 1];  // this commented stuff was when i tried to print ciphertext all at once
    for (int i = 0; i < key_length; i++)
    {
        char key_character = tolower(key[i]);
        difference_key_minus_alphabet[i] = key_character - alphabet[i];
    }
    for (int j = 0; j < plaintext_length; j++)
    {
        char plaintext_character = plaintext[j];
        if (isalpha(plaintext_character))
        {
            char *address_of_character_in_alphabet = strchr(alphabet, tolower(plaintext_character));
            int index_of_character_in_alphabet = address_of_character_in_alphabet - alphabet;
            char ciphertext_character = plaintext_character +  difference_key_minus_alphabet[index_of_character_in_alphabet];
            printf("%c", ciphertext_character);
            // // ciphertext[j] = ciphertext_character;                                  // all of this commented stuff was when i tried to print ciphertext all at once
            // strncat(ciphertext, &ciphertext_character, 1);
            // printf("ciphertext character[%i]:   %c\n", j, ciphertext_character);
        }
        else
        {
            printf("%c", plaintext_character);
            // char ciphertext_character = plaintext_character;
            // // ciphertext[j] = ciphertext_character;
            // strncat(ciphertext, &ciphertext_character, 1);
            // printf("ciphertext character[%i]:   %c\n", j, ciphertext_character);
        }
    }
    // printf("%s", ciphertext);
    // return ciphertext;
}

// test key: JTREKYAVOGDXPSNCUIZLFBMWHQ
// plaintext: hello
// ciphertext: vkxxn

// substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
// plaintext:  hello, world
// ciphertext: jrssb, ybwsp