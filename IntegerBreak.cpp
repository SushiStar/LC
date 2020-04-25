/*
 * Given a positive integer n, break it into the sum of at least two
 * positive integers and maximize the product of those integers. Return
 * the maximum product you can get.
 *
 * Date: 04/25/2020
 * Author: Wei Du
 */

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                auto tmp1 = std::max(dp[i - j] * dp[j], dp[i - j] * j);
                auto tmp2 = std::max(dp[j] * (i - j), (i - j) * j);
                dp[i] = std::max(dp[i], std::max(tmp1, tmp2));
            }
        }
        return dp.back();
    }
};
