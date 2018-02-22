#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define UPPERSTART 65;
#define UPPEREND 90;
#define LOWERSTART 97;
#define LOWEREND 122;

// get char starting from 0 from A-Z + a-z array: getChar(27) == b
char getChar(int i)
{
    if (i >= 0 && i <= 25)
    {
        return i + UPPERSTART;
    }
    else if (i >= 26 && i <= 51)
    {
        return i - 26 + LOWERSTART;
    }
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }

    string hash = argv[1];
    char salt[3] = {hash[0], hash[1], '\0'};

    for (int i = 0; i < 52; i++)
    {
        char password[5];
        password[0] = getChar(i);
        password[1] = '\0';

        if (!strcmp(crypt(password, salt), hash))
        {
            printf("%s\n", password);
        }
    }

    return 0;
}
