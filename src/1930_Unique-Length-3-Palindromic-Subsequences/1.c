// 0 ms (< 100.00%), 9.68 MB (< 28.60%)

#include <stdlib.h>
#define LENGTH 26

typedef unsigned int Charset;

void addChar(Charset* set, char c) {
    *set |= (1U << (c - 'a'));
}

int containsChar(Charset* set, char c) {
    return (*set >> (c - 'a')) & 1U;
}

int countPalindromicSubsequence(char* s) {
    int nSequence = 0;  // long long ?
    char* leftMost[LENGTH] = {NULL};
    char* rightMost[LENGTH] = {NULL};

    while (*s) {
        if (!leftMost[*s - 'a']) leftMost[*s - 'a'] = s;
        rightMost[*s - 'a'] = s;
        s++;
    }

    for (int i = 0; i < LENGTH; i++) {
        if (!leftMost[i] || (leftMost[i] == rightMost[i]) || (leftMost[i] + 1 == rightMost[i])) continue;

        Charset set = 0;
        int setSize = 0;
        char* start = leftMost[i];
        char* end = rightMost[i];

        while (start++ != end) {
            if (setSize == 26) break;
            if (start == end) break;
            if (!containsChar(&set, *start)) {
                addChar(&set, *start);
                setSize++;
            }
        }
        nSequence += setSize;
    }

    return nSequence;
}
