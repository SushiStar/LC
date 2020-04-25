/*
 * On a staircase, the i-th step has some non-negative cost cost[i]
 * assigned (0 indexed).
 *
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find the minimum cost to reach the top of the floor, and you can either
 * start from the step with index 0, or the step with index 1.
 *
 * Date: 04/25/2020
 * Author: Wei Du
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        if (cost.size() == 2) return std::min(cost[0], cost[1]);
        std::vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return std::min(dp.back(), dp[dp.size() - 2]);
    }
};
