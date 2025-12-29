// 130 ms (< 66.67%), 32.26 MB (< 66.67%)
// DFS with cache

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N 6

typedef struct Trie {
    struct Trie* next[N];
    int exists;  // -1: unknown, 0: doesn't exist, 1: exists
} Trie;

Trie* createTrie() {
    Trie* trie = (Trie*)calloc(1, sizeof(Trie));

    for (int i = 0; i < N; i++) {
        trie->next[i] = NULL;
    }
    trie->exists = -1;

    return trie;
}

void addWord(Trie* trie, char* word, int exists) {
    char* word_ptr = word;
    Trie* trie_ptr = trie;
    while (*word_ptr) {
        if (trie_ptr->next[*word_ptr - 'A'] == NULL) {
            trie_ptr->next[*word_ptr - 'A'] = createTrie();
        }
        trie_ptr = trie_ptr->next[*word_ptr++ - 'A'];
    }
    trie_ptr->exists = exists;
}

int findWord(Trie* trie, char* word) {
    char* word_ptr = word;
    Trie* trie_ptr = trie;
    while (*word_ptr) {
        if (trie_ptr->next[*word_ptr - 'A'] == NULL) {
            return -1;
        }
        trie_ptr = trie_ptr->next[*word_ptr++ - 'A'];
    }
    return trie_ptr->exists;
}

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N], Trie* trie);

bool DFS(char* bottom, bool possible[N][N][N], Trie* trie) {
    int length = strlen(bottom);
    if (length == 1) {
        return true;
    }

    char* nextLevel = (char*)calloc(length, sizeof(char));  // len(bottom) - 1 + sizeof('\0')

    return laterLevelExists(bottom, nextLevel, 0, possible, trie);
}

bool laterLevelExists(char* currentBottom, char* nextLevel, int index, bool possible[N][N][N], Trie* trie) {
    if (index == 0 && findWord(trie, currentBottom) == 0) {
        return false;
    }

    if (index == strlen(currentBottom) - 1) {
        nextLevel[index] = '\0';
        addWord(trie, currentBottom, 1);
        return DFS(nextLevel, possible, trie);
    }

    for (int i = 0; i < N; i++) {
        if (possible[currentBottom[index] - 'A'][currentBottom[index + 1] - 'A'][i]) {
            nextLevel[index] = i + 'A';
            if (laterLevelExists(currentBottom, nextLevel, index + 1, possible, trie)) return true;
        }
    }
    addWord(trie, currentBottom, 0);
    return false;
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    bool possible[N][N][N] = { false };

    for (int i = 0; i < allowedSize; i++) {
        possible[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A'] = true;
    }

    Trie* trie = createTrie();
    return DFS(bottom, possible, trie);
}
