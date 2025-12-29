// 139 ms (< 66.67%), 30.70 MB (< 66.67%)
// DFS with cache, bitmask

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define SIZE 1<<18


int get_key(char* s) {
    int key = 0;
    while (*s) key = (key << 3) | (*s++ - 'A');
    return key;
}

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N], signed char memo[N][SIZE]);

bool DFS(char* bottom, bool possible[N][N][N], signed char memo[N][SIZE]) {
    int length = strlen(bottom);
    if (length == 1) {
        return true;
    }

    char* nextLevel = (char*)calloc(length, sizeof(char));  // len(bottom) - 1 + sizeof('\0')

    return laterLevelExists(bottom, nextLevel, 0, possible, memo);
}

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N], signed char memo[N][SIZE]) {
    int len = strlen(currentBottom);
    int key = get_key(currentBottom);

    if (index == 0 && memo[len - 1][key] != -1) {
        return memo[len - 1][key];
    }

    if (index == strlen(currentBottom) - 1) {
        nextLevel[index] = '\0';
        memo[len - 1][key] = 1;
        return DFS(nextLevel, possible, memo);
    }

    for (int i = 0; i < N; i++) {
        if (possible[currentBottom[index] - 'A'][currentBottom[index + 1] - 'A'][i]) {
            nextLevel[index] = i + 'A';
            if (laterLevelExists(currentBottom, nextLevel, index + 1, possible, memo)) return true;
        }
    }
    memo[len - 1][key] = 0;
    return false;
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    bool possible[N][N][N] = { false };

    for (int i = 0; i < allowedSize; i++) {
        possible[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
    }

    signed char memo[N][SIZE];
    memset(memo, -1, sizeof(memo));
    return DFS(bottom, possible, memo);
}
