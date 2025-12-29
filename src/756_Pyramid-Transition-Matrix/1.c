// DFS, Time Limit Exceeded

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N 6

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N]);

bool DFS(char* bottom, bool possible[N][N][N]) {
    int length = strlen(bottom);
    if (length == 1) {
        return true;
    }

    char* nextLevel = (char*)calloc(length, sizeof(char));  // len(bottom) - 1 + sizeof('\0')

    return laterLevelExists(bottom, nextLevel, 0, possible);
}

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N]) {
    if (index == strlen(currentBottom) - 1) {
        nextLevel[index] = '\0';
        return DFS(nextLevel, possible);
    }

    for (int i = 0; i < N; i++) {
        if (possible[currentBottom[index] - 'A'][currentBottom[index + 1] - 'A'][i]) {
            nextLevel[index] = i + 'A';
            if (laterLevelExists(currentBottom, nextLevel, index + 1, possible)) return true;
        }
    }
    return false;
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    bool possible[N][N][N] = { false };

    for (int i = 0; i < allowedSize; i++) {
        possible[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
    }

    return DFS(bottom, possible);
}
