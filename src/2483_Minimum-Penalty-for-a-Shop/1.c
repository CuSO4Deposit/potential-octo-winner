// 7 ms (< 66.67%), 13.44 MB (< 33.33%)

int bestClosingTime(char* customers) {
    int length = 0;
    int initial_penalty = 0;
    char* ptr = customers;

    while (*ptr) {
        length++;
        if (*ptr++ == 'Y') {
            initial_penalty++;
        }
    }

    int* penalty = (int*)malloc((length + 1) * sizeof(int));
    if (length) penalty[0] = initial_penalty;

    for (int i = 1; i < length + 1; i++) {
        penalty[i] = penalty[i - 1] + (customers[i - 1] == 'N' ? 1 : -1);
    }

    int idx = 0;
    for (int i = 0; i < length + 1; i++) {
        if (penalty[i] < penalty[idx]) idx = i;
    }

    return idx;
}
