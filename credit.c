#include <stdio.h>

int main(void) {
    long long card;
    int checkSum;

    do {
        scanf("%lld", &card);
    }
    while (card <= 0);

    while (card != 0) {
        int odd = card/10%10 * 2;
        int even = card%10;

        if (odd/10 != 0) {
            checkSum += odd/10 + odd%10;
        } else {
            checkSum += odd;
        }

        checkSum += even;

        card /= 100;
    }

    printf("Your checksum is %d. ", checkSum);
    if (checkSum % 10 == 0) {
        printf("Congratulations! Your card is valid!\n");
    } else {
        printf("Sorry, you've entered an invalid card.\n");
    }
}
