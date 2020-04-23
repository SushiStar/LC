/*
 * Say you have an array for which the i-th element is the price of
 * a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at
 * most  k transactions.
 * Note: You may not engage in multiple transactions at the same time.
 *
 * Date: 04/22/2020
 * Author: Wei Du
 */

// learned DP again, should pay more attention to repeated stuff.
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (k == 0 || prices.empty()) return 0;
        if (k >= prices.size() / 2) {
            int ret{0};
            for (int i = 1; i < prices.size(); ++i)
                ret += std::max(prices[i] - prices[i - 1], 0);
            return ret;
        }

        std::vector<std::vector<int>> dp(k + 1,
                                         std::vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; ++i) { // ith chance
            int tmpMax = -prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                // do nothing, or sell
                dp[i][j] = std::max(dp[i][j - 1], prices[j] + tmpMax);
                tmpMax = std::max(tmpMax, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp.back().back();
    }
};

