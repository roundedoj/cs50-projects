#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Get key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];

    // Validate key
    // Check if key contains 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Check if key contains only alphabetic characters and if there are any repeated characters
    int letter_count[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }

        int index = toupper(key[i]) - 'A';
        letter_count[index]++;
        if (letter_count[index] > 1)
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }
    }

    // Collect plaintext
    string plaintext = get_string("Enter plaintext: ");

    // Generate ciphertext ensuring that it maps to the matching letter in the key and is case sensitive
    printf("ciphertext: ");
    for (int i = 0, text_length = strlen(plaintext); i < text_length; i++)
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 'A';
                printf("%c", toupper(key[index]));
            }

            else if (islower(plaintext[i]))
            {
                int index = plaintext[i] - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    printf("\n");
    return 0;
}
