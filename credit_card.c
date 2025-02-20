#include <cs50.h>
#include <stdio.h>

int get_digit_count(long card_number);

int get_starting_digits(long card_number, int n);

bool is_card_valid(long card_number);

string get_card_type(long card_number);

int main(void)
{
    long card_number = get_long("Enter card number: ");

    if (is_card_valid(card_number))
    {
        string card_type = get_card_type(card_number);
        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int get_digit_count(long card_number)
{
    int count = 0;

    while (card_number != 0)
    {
        card_number /= 10;
        count++;
    }

    return count;
}

int get_starting_digits(long card_number, int n)
{
    int digit_count = get_digit_count(card_number);
    long divisor = 1;

    for (int i = 0; i < digit_count - n; i++)
    {
        divisor *= 10;
    }

    return card_number / divisor;
}

bool is_card_valid(long card_number)
{
    int sum_odd_digits = 0;
    int sum_even_digits = 0;
    bool is_second_digit = false;

    while (card_number > 0)
    {
        int digit = card_number % 10;

        if (is_second_digit)
        {
            int product = digit * 2;

            if (product > 9)
            {
                sum_even_digits += product % 10 + product / 10;
            }
            else
            {
                sum_even_digits += product;
            }
        }
        else
        {
            sum_odd_digits += digit;
        }

        card_number /= 10;
        is_second_digit = !is_second_digit;
    }
    int sum_total_digits = sum_odd_digits + sum_even_digits;
    return (sum_total_digits % 10 == 0);
}

string get_card_type(long card_number)
{
    int digit_count = get_digit_count(card_number);
    long starting_digit_2 = get_starting_digits(card_number, 2);
    long starting_digit_1 = get_starting_digits(card_number, 1);

    if (digit_count == 15 && (starting_digit_2 == 34 || starting_digit_2 == 37))
    {
        return "AMEX";
    }
    else if (digit_count == 16 && (starting_digit_2 >= 51 && starting_digit_2 <= 55))
    {
        return "MASTERCARD";
    }
    else if ((digit_count == 13 || digit_count == 16) && starting_digit_1 == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
