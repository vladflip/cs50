#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// move ASCII code c character by k numbers in an alphabetical range
char crypt(int c, int k)
{
    // subtract from actual ascii index in order to calculate it in a 26 digits range
    int move;

    if (isupper(c))
    {
        if (!(c >= 65 && c <= 90))
        {
            return c;
        }
        move = 64;
    }
    else
    {
        if (!(c >= 97 && c <= 122))
        {
            return c;
        }
        move = 96;
    }

    return (c - move + k) % 26 + move;
}

int main(int argc, string argv[])
{
    string plaintext;

    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }

    int k = atoi(argv[1]);

    plaintext = get_string("plaintext:");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", crypt(plaintext[i], k));
    }

    printf("\n");

    return 0;
}