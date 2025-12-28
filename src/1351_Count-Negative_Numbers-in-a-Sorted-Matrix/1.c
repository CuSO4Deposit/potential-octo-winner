// 0 ms (< 100.00%), 9.91 MB (< 11.52%)

int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int num = 0;
    int maxCol = gridColSize[0] - 1;
    for (int row = 0; row < gridSize; row++) {
        while (maxCol >= 0) {
            if (grid[row][maxCol] >= 0) {
                break;
            }
            maxCol--;
        }
        num += (maxCol >= 0) ? (gridColSize[row] - maxCol - 1) : gridColSize[row];
    }

    return num;
}
