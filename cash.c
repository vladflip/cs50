#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int coins[4] = {25, 10, 5, 1};
    int change;
    int amount;
    float tempChange;

    do
    {
        tempChange = get_float("Change owed: ");
    }
    while (tempChange <= 0);

    change = tempChange * 100 + .5;

    printf("%d\n", change);

    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
    {
        while (change / coins[i] != 0)
        {
            change = change - coins[i];
            amount++;
        }
    }

    printf("%d\n", amount);
}
