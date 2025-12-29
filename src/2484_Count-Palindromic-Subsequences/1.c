// This algorithm is not correct. The palindrome is defined to be combined arbitarily,
// for example for '0000000' there are 21 possibilities, while this algorithm give 4.

#include <stdlib.h>
#define LENGTH 10

typedef unsigned int Digitset;

void addDigit(Digitset* set, char c) {
    *set |= (1U << (c - '0'));
}

int containsDigit(Digitset* set, char c) {
    return (*set >> (c - '0') & 1U);
}

int countPalindromes(char* s) {
    char* ptr = s;

    Digitset leftmostSet = 0;
    int leftmostSetSize = 0;
    int digitsLeft = LENGTH * LENGTH;
    char*** leftmostDigits = (char***)calloc(LENGTH, sizeof(char**));
    for (int i = 0; i < LENGTH; i++) {
        leftmostDigits[i] = (char**)calloc(LENGTH, sizeof(char**));
    }

    while (*ptr) {
        for (int i = 0; i < LENGTH; i++) {
            if (!digitsLeft) break;
            if (leftmostDigits[i][*ptr - '0']) continue;
            if ((leftmostSetSize == LENGTH) || containsDigit(&leftmostSet, i + '0')) {
                leftmostDigits[i][*ptr - '0'] = ptr;
                digitsLeft--;
            }
            if (leftmostSetSize != LENGTH) {
                addDigit(&leftmostSet, *ptr);
                leftmostSetSize++;
            }
        }
        ptr++;
    }
    char* sEnd = ptr - 1;

    Digitset rightmostSet = 0;
    int rightmostSetSize = 0;
    digitsLeft = LENGTH * LENGTH;
    char*** rightmostDigits = (char***)calloc(LENGTH, sizeof(char**));
    for (int i = 0; i < LENGTH; i++) {
        rightmostDigits[i] = (char**)calloc(LENGTH, sizeof(char*));
    }

    ptr = sEnd;
    while (ptr != s) {
        for (int i = 0; i < LENGTH; i++) {
            if (!digitsLeft) break;
            if (rightmostDigits[i][*ptr - '0']) continue;
            if ((rightmostSetSize == LENGTH) || containsDigit(&rightmostSet, i + '0')) {
                rightmostDigits[i][*ptr - '0'] = ptr;
                digitsLeft--;
            }
            if (rightmostSetSize != LENGTH) {
                addDigit(&rightmostSet, *ptr);
                rightmostSetSize++;
            }
        }
        ptr--;
    }

    const unsigned int modulo = 1e9 + 7;
    unsigned int num = 0;

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (!leftmostDigits[i] || !rightmostDigits[i] || leftmostDigits[i][j] == rightmostDigits[i][j]) continue;
            int delta = rightmostDigits[i][j] - leftmostDigits[i][j] - 1;
            num = ((num % modulo) + (delta % modulo)) % modulo;
        }
    }

    for (int i = 0; i < LENGTH; i++) {
        free(leftmostDigits[i]);
    }
    free(leftmostDigits);
    for (int i = 0; i < LENGTH; i++) {
        free(rightmostDigits[i]);
    }
    free(rightmostDigits);

    return num;
}
