// 102 ms (< 61.27%), 198.61 MB (< 73.99%)
#include <math.h>
#include <vector>

class Solution {
public:
    double upperMinusLower(std::vector<std::vector<int>>& squares, double split) {
        double result = 0;
        for (auto& square : squares) {
            int y = square[1];
            int l = square[2];
            if (split < y) result += (double)l * l;
            else if (split > y+l) result -= (double)l * l;
            else result += (2.0 * y + l - 2 * split) * l;
        }
        return result;
    }

    // Binary search on a unit range to reach 1E-5 precision should take less than 20 times
    double separateSquares(std::vector<std::vector<int>>& squares) {
        double low = 2E9;
        double high = 0;
        for (auto& square : squares) {
            int y = square[1];
            int l = square[2];
            if (y < low) low = y;
            if (y+l > high) high = y+l;
        }

        double mid;
        while (std::abs(low - high) > 1E-6) {
            mid = (low + high) / 2;
            double split = upperMinusLower(squares, mid);
            if (split > 0) low = mid;
            else high = mid;
        }

        return mid;
    }
};
