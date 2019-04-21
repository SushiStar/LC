/*
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such
 * that the sum of elements in each subsets is equal.
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * Backtracking Get:)
 *
 * Date: Apr/21/2019
 * Author: Wei Du
 */
#include <functional>
#include <numeric>
#include <vector>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;  // if its odd number, no solution
        sum /= 2;
        sort(nums.begin(), nums.end());
        return helper(nums, sum, 0);
    }
    bool helper(vector<int>& nums, int sum, int index) {
        if (index >= nums.size() || sum < nums[index]) return false;
        if (sum == nums[index]) return true;
        return helper(nums, sum - nums[index], index + 1) ||
               helper(nums, sum, index + 1);
    }
};

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
    if (sum & 1) return false;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (auto num : nums)
        for (int i = target; i >= num; i--) dp[i] = dp[i] || dp[i - num];
    return dp[target];
}
