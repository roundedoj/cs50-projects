#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_points_score(string input);

int main(void)
{
    // collect user inputs
    string input_1 = get_string("Player 1, enter a word: ");
    string input_2 = get_string("Player 2, enter a word: ");

    // calculate points
    int score_1 = get_points_score(input_1);
    int score_2 = get_points_score(input_2);

    // declare result
    if (score_1 > score_2)
    {
        printf("Player 1 wins! (%d points)\n", score_1);
    }

    else if (score_1 < score_2)
    {
        printf("Player 2 wins! (%d points)\n", score_2);
    }

    else
    {
        printf("It's a tie! (%d points)\n", score_1);
    }
}

int get_points_score(string input)
{
    int score = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isupper(input[i]))
        {
            score += POINTS[input[i] - 'A'];
        }

        else if (islower(input[i]))
        {
            score += POINTS[input[i] - 'a'];
        }
    }
    return score;
}
