/*
 * You are given coins of different denominations, and a total
 * amount of money amount.  Write a function to compute the
 * fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination
 * of the coins, return -1.
 *
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return amount;
        std::vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (i>=c) dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};
