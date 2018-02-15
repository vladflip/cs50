#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long card, CARD;
    int checkSum = 0;
    int counter = 0;
    int firstNumber = 0;

    do
    {
        card = get_long_long("Prompt: ");
    }
    while (card <= 0);

    // cache card
    CARD = card;

    while (card != 0)
    {
        counter++;
        int lastDigit = card % 10;

        if (card / 100 == 0 && firstNumber == 0)
        {
            firstNumber = card;
        }

        // odd
        // even
        if (counter & 1)
        {
            checkSum += lastDigit;
        }
        else
        {
            if (lastDigit * 2 / 10 != 0)
            {
                checkSum += lastDigit * 2 / 10 + lastDigit * 2 % 10;
            }
            else
            {
                checkSum += lastDigit * 2;
            }
        }

        card /= 10;
    }

    int visa = 0;
    int masterCard = 0;
    int amex = 0;

    if (checkSum % 10 == 0)
    {
        if (counter == 13)
        {
            visa = 1;
        }
        else if (counter == 15 && (firstNumber == 34 || firstNumber == 37))
        {
            amex = 1;
        }
        else if (counter == 16)
        {
            if (firstNumber / 10 == 4)
            {
                visa = 1;
            }
            else if (firstNumber >= 51 && firstNumber <= 55)
            {
                masterCard = 1;
            }
        }
    }

    if (visa)
    {
        printf("VISA\n");
    }
    else if (amex)
    {
        printf("AMEX\n");
    }
    else if (masterCard)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
