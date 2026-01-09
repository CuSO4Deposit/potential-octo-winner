// 12 ms (< 82.00%), 17.78 MB (< 54.80%)
#include <algorithm>
#include <vector>

class Solution {
public:
    // dp[i][j] is the max dot prod of nums1[:i-1] and nums2[:j-1]
    // dp[i][j] = max {
    //      nums1[i-1] * nums2[j-1]
    //      dp[i-1][j-1] + nums1[i-1]*nums2[j-1]
    //      dp[i-1][j]
    //      dp[i][j-1]
    // }
    int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1E7));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int current = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = std::max({
                    current,
                    dp[i-1][j-1] + current,
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }

        return dp[m][n];
    }
};
