// 0 ms (< 100.00%), 8.41 MB (< 75.00%)

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    // Center of a magic square must be 5.
    int offsetsI[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int offsetsJ[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int num = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] != 5) continue;
            if (i < 1 || j < 1 || i >= gridSize - 1 || j >= gridColSize[i] - 1) continue;

            int failed = 0;
            for (int k = 1; k < 8; k++) {
                int value = grid[i + offsetsI[k]][j + offsetsJ[k]];
                if (value == 5 || value > 9) {
                    failed = 1;
                    break;
                };
            }
            int diagsum = 0;
            int adiagsum = 0;
            for (int p = -1; (!failed) && p <= 1; p++) {
                int rowsum = 0;
                int colsum = 0;
                for (int q = -1; q <= 1; q++) {
                    rowsum += grid[i + p][j + q];
                    colsum += grid[i + q][j + p];
                }
                diagsum += grid[i + p][j + p];
                adiagsum += grid[i + p][j - p];
                if (rowsum != 15 || colsum != 15) {
                    failed = 1;
                    break;
                }
            }
            if (diagsum != 15 || adiagsum != 15) failed = 1;

            num += !failed;
        }
    }

    return num;
}
