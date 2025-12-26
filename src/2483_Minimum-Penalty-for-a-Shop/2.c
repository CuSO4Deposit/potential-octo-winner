// 4 ms (< 66.67%), 9.36 MB (< 66.67%)

int bestClosingTime(char* customers) {
    int penalty = 0;
    int min_penalty = 0;

    int idx_current = 0;
    int idx = 0;

    while (*customers) {
        penalty += (*customers++ == 'N' ? 1 : -1);
        if (penalty < min_penalty) {
            idx = idx_current + 1;
            min_penalty = penalty;
        }
        idx_current++;
    }

    return idx;
}
