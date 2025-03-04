#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    // receive user input
    string text = get_string("Enter text (at least one sentence) to know your reading level: ");

    // count the number of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // treat edge cases
    if (letters == 0 || words == 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    else
    {
        // implement Coleman-Liau's Index
        float L = (letters / (float) words) * 100;
        float S = (sentences / (float) words) * 100;
        int index = round((0.0588 * L) - (0.296 * S) - 15.8);

        // print results
        if (index < 1)
        {
            printf("Reading level: Before Grade 1\n");
        }

        else if (index >= 1 && index <= 16)
        {
            printf("Reading level: Grade %d\n", index);
        }

        else
        {
            printf("Reading level: Grade 16+\n");
        }

        return 0;
    }
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (isalnum(text[i]))
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (isspace(text[i]))
        {
            word_count += 1;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}
