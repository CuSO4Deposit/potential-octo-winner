#include <string.h>
#define LENGTH 10

int countPalindromes(char* s){
    char* pivot = s;
    int subsequenceLeft[LENGTH][LENGTH] = {0};
    int subsequenceRight[LENGTH][LENGTH] = {0};
    const long long modulo = 1e9 + 7;
    unsigned long long num = 0;
    while (*pivot) {
        memset(subsequenceLeft, 0, sizeof(subsequenceLeft));
        memset(subsequenceRight, 0, sizeof(subsequenceRight));

        char* current = s;
        while (current + 1 < pivot) {
            subsequenceLeft[*current - '0'][*(current + 1) - '0']++;
            current++;
        }

        current = pivot + 1;
        while (*current && *(current + 1)) {
            subsequenceRight[*current - '0'][*(current + 1) - '0']++;
            current++;
        }

        pivot++;
        for (int i = 0; i < LENGTH; i++) {
             for (int j = 0; j < LENGTH; j++) {
                unsigned long long sum = (unsigned long long)subsequenceLeft[i][j] * subsequenceRight[j][i];
                num = (num + sum) % modulo;
             }
        }
    }

    return num;
}
