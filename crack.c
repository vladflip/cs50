#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

#define UPPERSTART 65;
#define UPPEREND 90;
#define LOWERSTART 97;
#define LOWEREND 122;

// increment char by one in its alphabetical array
char incrementChar(char c)
{
    if (c == 90)
    {
        return 97;
    }
    return c + 1;
}

int main(void)
{
    /*
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }

    string hash = argv[1];
    char salt[3] = {hash[0], hash[1], '\0'};
    */

    int n = 3;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < n; i++)
    {
        char password[n];
        password[i + 1] = '\0';

        // compose a string
        for (int j = 0; j < i + 1; j++)
        {
            password[j] = UPPERSTART;
        }

        printf("%sCOMPOSED\n", password);

        for (int j = 0, c = 0, place = n - 1; j < /*(int)pow(52, i + 1)*/ 52*52; j++)
        {
            password[i] = alphabet[c];

            printf("%s-", password);


            // alphabetical permutation
            if (c == 51)
            {
                c = 0;
                // use the place value
                password[i - 1] = incrementChar(password[i - 1]);
                printf("\n");
                
                // move the place value to the left
                // it should check if its a last letter, if yes
                // then reset it to a first one, repeat up to the first place
            }
            else
            {
                c++;
            }

            /*
            if (!strcmp(crypt(password, salt), hash))
            {
                printf("%s\n", password);
            }
            */
        }

        printf("\n");
    }

    return 0;
}
