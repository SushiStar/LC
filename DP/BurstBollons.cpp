/*
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted
 * with a number on it represented by array nums. You are asked to
 * burst all the balloons. If the you burst balloon i you will get
 * nums[left] * nums[i] * nums[right] coins. Here left and right are
 * adjacent indices of i. After the burst, the left and right then
 * becomes adjacent.
 * Note: 0<=n<=500, 0<=nums[i]<=100
 *
 * Date: 04/12/2020
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        if (nums.empty()) return 0;
        std::vector<int> inums;
        inums.push_back(1);
        for (auto num : nums) { // burst number with 0
            if (num) inums.push_back(num);
        }
        inums.push_back(1);
        int sz = inums.size();
        std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, 0));
        for (int i = 2; i < sz; ++i) { // satrt from range 2
            for (int left = 0; left < sz - i; ++left) {
                int right = left + i;
                for (int j = left + 1; j < right; ++j) {
                    dp[left][right] = max(
                        dp[left][right], inums[left] * inums[j] * inums[right] +
                                             dp[left][j] + dp[j][right]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};
