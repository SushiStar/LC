/*
 * You are given coins of different denominations and a total amount of
 * money amount. Write a function to compute the fewest number of coins
 * that you need to make up that amount. If that amount of money cannot
 * be made up by any combination of the coins, return -1.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        std::unordered_map<int, int> dp;
        for (auto c : coins)
            dp[c] = 1;
        dp[1] = dp[1] > 0 ? dp[1] : INT_MAX;
        for (int i = 2; i <= amount; ++i) {
            if (dp[i] == 0) dp[i] = INT_MAX;
            for (auto c : coins) {
                if (i > c && dp[i - c] < INT_MAX)
                    dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
