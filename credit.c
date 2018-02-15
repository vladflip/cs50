#include <stdio.h>

int main(void) {
    long long card, CARD;
    int checkSum;
    int counter = 0;
    int firstDigit;

    do {
        scanf("%lld", &card);
    }
    while (card <= 0);

    CARD = card; 
    
    while (card != 0) {
        counter++;
        int lastDigit = card%10;

        if (lastDigit / 10 == 0) {
            firstDigit = lastDigit;
        }

        // odd
        // even
        if (counter & 1) {
            checkSum += lastDigit;
        } else {
            if (lastDigit*2 / 10 != 0) {
                checkSum += lastDigit*2 / 10 + lastDigit*2 % 10;
            } else {
                checkSum += lastDigit * 2;
            }
        }

        card /= 10;
    }

    int visa, masterCard, amex = 0;

    printf("Your checksum is %d. ", checkSum);

    if (checkSum % 10 == 0) {
        printf("Congratulations! Your card is valid!\n");

        if (counter == 13) {
            visa = 1;
        } else if (counter == 15) {
            amex = 1;
        } else if (counter == 16) {
            if (firstDigit == 4) {
                visa = 1;
            } else {
                masterCard = 1;
            }
        }
    } else {
        printf("Sorry, you've entered an invalid card.\n");
    }

    if (visa) {
        printf("Your card company is Visa.\n");
    } else if (amex) {
        printf("Your card company is Amex.\n");
    } else if (masterCard) {
        printf("Your card company is MasterCard.\n");
    }
}
