// binary search + DFS, O(n log n), Time Limit Exceeded

#include <stdlib.h>
#include <string.h>

void initLandAtDay(char** land, int day, int** cells, int cellsSize, int* cellsColSize) {
    for (int currentDay = 0; currentDay < cellsSize; currentDay++) {
        land[cells[currentDay][0] - 1][cells[currentDay][1] - 1] = (currentDay < day) ? 1 : 0;
    }
}

int DFS(char** land, int row, int col, int i, int j, char** visited) {
    if (i == row - 1 && land[i][j] == 0) return 1;
    if (i == -1 && j == -1) {
        for (int q = 0; q < col; q++) {
            if (DFS(land, row, col, 0, q, visited)) return 1;
        }
    } else if (land[i][j] == 0) {
        if (visited[i][j]) return 0;
        visited[i][j] = 1;
        char dx[] = {0, 0, 1, -1};
        char dy[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (ii < 0 || jj < 0 || ii >= row || jj >= col) continue;
            if (DFS(land, row, col, ii, jj, visited)) return 1;
        }
    }

    return 0;
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    char** land = (char**)calloc(row, sizeof(char*));
    for (int i = 0; i < row; i++) land[i] = (char*)calloc(col, sizeof(char));

    char** visited = (char**)calloc(row, sizeof(char*));
    for (int i = 0; i < row; i++) visited[i] = (char*)calloc(col, sizeof(char));

    int low = 0;
    int high = cellsSize;
    while (low < high) {
        int mid = low + (high - low) / 2;
        for (int i = 0; i < row; i++) memset(visited[i], 0, col);
        initLandAtDay(land, mid, cells, cellsSize, cellsColSize);
        if (DFS(land, row, col, -1, -1, visited)) {
            low = mid + 1;
        } else {
            high = mid;
        };
    }

    for (int i = 0; i < row; i++) free(land[i]);
    free(land);

    return low - 1;
}
