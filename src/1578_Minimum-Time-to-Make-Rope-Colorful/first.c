// 4 ms (< 48.56%), 16.95 MB (< 38.62%)

int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int total_cost = 0;

    for (int i = 0; i < neededTimeSize - 1; i++) {
        if (colors[i] == colors[i + 1]) {
            if (neededTime[i] < neededTime[i + 1]) {
                total_cost += neededTime[i];
            } else {
                total_cost += neededTime[i + 1];
                neededTime[i + 1] = neededTime[i];
            }
        }
    }
    return total_cost;
}
