// 70 ms (< 52.58%), 34.50 MB (< 52.58%)
// binary search + DFS, O(n log n), slightly cleaner

#include <stdlib.h>
#include <string.h>

void initLandAtDay(char** land, int day, int** cells, int cellsSize, int* cellsColSize) {
    for (int currentDay = 0; currentDay < cellsSize; currentDay++) {
        // This is a clever way to set the whole grid without memset
        // 1 is water, 0 is land
        land[cells[currentDay][0] - 1][cells[currentDay][1] - 1] = (currentDay < day) ? 1 : 0;
    }
}

// Standard recursive DFS. Returns 1 if a path to the bottom is found.
int DFS(char** land, int row, int col, int r, int c, char** visited) {
    // Check boundaries, if it's water, or if already visited
    if (r < 0 || r >= row || c < 0 || c >= col || land[r][c] == 1 || visited[r][c]) {
        return 0;
    }
    // Mark as visited
    visited[r][c] = 1;

    // If we are at the last row, we found a path
    if (r == row - 1) {
        return 1;
    }

    // Explore neighbors
    if (DFS(land, row, col, r + 1, c, visited)) return 1;
    if (DFS(land, row, col, r - 1, c, visited)) return 1;
    if (DFS(land, row, col, r, c + 1, visited)) return 1;
    if (DFS(land, row, col, r, c - 1, visited)) return 1;

    return 0;
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    char** land = (char**)calloc(row, sizeof(char*));
    for (int i = 0; i < row; i++) land[i] = (char*)calloc(col, sizeof(char));

    char** visited = (char**)calloc(row, sizeof(char*));
    for (int i = 0; i < row; i++) visited[i] = (char*)calloc(col, sizeof(char));

    int ans = 0;
    int low = 0;
    // Search up to cellsSize, as it's possible to cross on the last day
    int high = cellsSize; 

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) { // Day 0, all land, always possible
            low = mid + 1;
            continue;
        }

        initLandAtDay(land, mid, cells, cellsSize, cellsColSize);
        for (int i = 0; i < row; i++) memset(visited[i], 0, col);

        int can_cross = 0;
        // Check for a path starting from any cell in the top row
        for (int j = 0; j < col; j++) {
            if (land[0][j] == 0 && !visited[0][j]) {
                if (DFS(land, row, col, 0, j, visited)) {
                    can_cross = 1;
                    break;
                }
            }
        }

        if (can_cross) {
            ans = mid; // This day is possible, try a later day
            low = mid + 1;
        } else {
            high = mid - 1; // This day is not possible, try an earlier day
        }
    }

    for (int i = 0; i < row; i++) {
        free(land[i]);
        free(visited[i]);
    }
    free(land);
    free(visited);

    return ans;
}
