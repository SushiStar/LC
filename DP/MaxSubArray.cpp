/*
 * Given an integer array nums, find the continguous subrrary (containing at
 * least one number) which has the largest sum and return its sum.
 * // DP idea: dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
 *
 * Date: 03/07/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) return 0;
        int sum{0};
        int maxSum{INT_MIN};
        for (auto &num : nums) {
            sum = sum > 0 ? sum + num : num;
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }
};
