/*
 * You are professional robber planning to rob houses along a street. Each house
 * has a certain amount money stashed, the only constraint stopping you from
 * robbing each of them is that adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were
 * broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Date: Apr/08/2019
 *
 * Author: Wei Du
 */
class Solution {
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        nums.insert(nums.begin(), 0);
        std::vector<int> acc(nums.size());
        acc[0] = nums[0];  // the extra one;
        acc[1] = nums[1];  // the real first one;
        acc[2] = nums[2];
        for (int i = 3; i < nums.size(); ++i) {
            int a = acc[i - 3] + nums[i];
            int b = acc[i - 2] + nums[i];
            acc[i] = max(a, b);
        }
        return max(acc.back(), acc[acc.size() - 2]);
    }
};
