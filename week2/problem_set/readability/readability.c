#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    // printf("%i letters\n", letters);
    int words = count_words(text);
    // printf("%i words\n", words);
    int sentences = count_sentences(text);
    // printf("%i sentences\n", sentences);
    float l =  (float) letters / words * 100;// average number of letters per 100 words
    // printf("%f letters per 100 words\n", l);
    float s =  (float) sentences / words * 100;// average number of sentences per 100 words
    // printf("%f sentences per 100 words\n", s);
    float index = .0588*l - .296*s - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int rounded_index = round(index);
        printf("Grade %i\n", rounded_index);
    }
}

int count_letters(string text)
{
    int letters_sum = 0;
    for (int i = 0, n = strlen(text); i < n;i++)
    {
        if ((65 <= text[i] && text[i] <= 90) ||
            (97 <= text[i] && text[i] <= 122))
            letters_sum += 1;
    }
    return letters_sum;
}

int count_words(string text)
{
    int words_sum = 0;
    for (int i = 0, n = strlen(text); i < n;i++)
    {
        if (text[i] == 32)
        {
            words_sum += 1;
        }
    }
    words_sum += 1;
    return words_sum;
}

int count_sentences(string text)
{
    int sentences_sum = 0;
    for (int i = 0, n = strlen(text); i < n;i++)
    {
        if (text[i] == 33 ||
            text[i] == 46 ||
            text[i] == 63)
            {
                sentences_sum += 1;
            }
    }
    return sentences_sum;
}
