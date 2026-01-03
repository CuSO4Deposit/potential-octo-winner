// 0 ms (< 100.00%), 7.78 MB (< 86.67%)
// +Binary_Exponentiation
// f(n) = [[3, 2], [2, 2]] ^ (n - 1) @ [6, 6]; g(n) = 1^T @ f(n).
class Solution {
public:
    int numOfWays(int n) {
        long long a = 6, b = 6;
        long long tmp = a;
        const int modulo = 1E9 + 7;

        long long m11 = 3, m12 = 2, m21 = 2, m22 = 2;
        int p = n - 1;
        while (p > 0) {
            if (p & 1) {
                tmp = (m11 * a + m21 * b) % modulo;
                b = (m12 * a + m22 * b) % modulo;
                a = tmp;
            }
            long long n11 = (m11 * m11 + m12 * m21) % modulo;
            long long n12 = (m11 * m12 + m12 * m22) % modulo;
            long long n21 = (m21 * m11 + m22 * m21) % modulo;
            long long n22 = (m21 * m12 + m22 * m22) % modulo;
            m11 = n11; m12 = n12; m21 = n21; m22 = n22;

            p >>= 1;
        }
        return (a + b) % modulo;
    }
};
