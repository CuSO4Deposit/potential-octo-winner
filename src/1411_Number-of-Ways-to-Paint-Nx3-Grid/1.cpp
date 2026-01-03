// 0 ms (< 100.00%), 7.84 MB (< 70.00%)
// f(n) = [[3, 2], [2, 2]] ^ (n - 1) @ [6, 6]; g(n) = 1^T @ f(n).
class Solution {
public:
    int numOfWays(int n) {
        long long a = 6; long long b = 6;
        long long tmp = a;
        const int modulo = 1E9 + 7;
        for (int i = 0; i < n - 1; i++) {
            tmp = (3 * a + 2 * b) % modulo;
            b = (2 * a + 2 * b) % modulo;
            a = tmp;
        }
        return (a + b) % modulo;
    }
};
