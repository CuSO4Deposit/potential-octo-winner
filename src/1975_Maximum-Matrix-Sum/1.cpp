// You can filp any of the 2 elements at once, so finally there are 1 or 0
// negative elements, depending on the original negative elements num.
// 2 ms (< 49.06%), 39.11 MB (< 61.32 %)

#include <cstdlib>
#include <vector>

class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        int smallestAbs = std::abs(matrix[0][0]);
        int negativeNum = 0;
        long long sum = 0;

        for (auto& row : matrix) {
            for (int& col : row) {
                if (col < 0) {
                    col = -col;
                    negativeNum++;
                }
                if (col < smallestAbs) smallestAbs = col;
                sum += col;
            }
        }
        if (negativeNum % 2 == 1) sum -= 2 * smallestAbs;

        return sum;
    }
};
