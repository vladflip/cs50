#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define UPPERSUB 65;
#define LOWERSUB 97;

// returns character alphabetical place number
// starting from 0 case insensitive (a/A is 0, b/B is 1)
int getCharAlphaPlace(char c)
{
    if (isupper(c))
    {
        return c - UPPERSUB;
    }
    else
    {
        return c - LOWERSUB;
    }
}

// move ASCII code c character by k char alphabetical place number
char crypt(int c, char k)
{
    int move;

    if (isupper(c))
    {
        if (!(c >= 65 && c <= 90))
        {
            return c;
        }
        move = UPPERSUB;
    }
    else
    {
        if (!(c >= 97 && c <= 122))
        {
            return c;
        }
        move = LOWERSUB;
    }

    return (c - move + getCharAlphaPlace(k)) % 26 + move;
}

// get cyclical char from the key phrase
char getKeyChar(string phrase, int i)
{
    return phrase[i % strlen(phrase)];
}

int isAlphabetical(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, string argv[])
{
    string plaintext;

    if (argc != 2 || !isAlphabetical(argv[1]))
    {
        printf("Usage: ./vigenere phrase\n");
        return 1;
    }

    string key = argv[1];

    plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        printf("%c", crypt(plaintext[i], getKeyChar(key, j)));

        if (isalpha(plaintext[i]))
        {
            j++;
        }
    }

    printf("\n");

    return 0;
}
