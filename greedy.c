#include <stdio.h>

int main (void) {
    int coins[4] = {25, 10, 5, 1};
    int change;
    int amount;
    float tempChange;

    do {
        scanf("%f", &tempChange);
    }
    while (tempChange <= 0);

    change = tempChange * 100;

    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++) {
        while (change / coins[i] != 0) {
            change = change - coins[i];
            amount++;
        }
    }

    printf("%d", amount);
}
