/*
 * You are climbing a stair case. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways
 * can you climb to the top?
 *
 * Given n will be a positive integer.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < dp.size(); ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp.back();
    }
};
