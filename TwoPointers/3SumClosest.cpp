/*
 * Given an array nums of n integers, and in integer target,
 * find three integers in nums, such that the sum is closest
 * to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * Date: 03/09/2020
 *
 * Autor: Wei Du
 *
 */

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int sum = INT_MAX;
        int error = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            int current = 0;
            int tempError = 0;
            while (l < r) {
                current = nums.at(i) + nums.at(l) + nums.at(r);
                tempError = std::abs(current - target);
                if (tempError < error) {
                    sum = current;
                    error = tempError;
                    if (error == 0) return sum;
                }
                if (current < target) {
                    ++l;
                } else {
                    --r;
                }
            }
            while (i < nums.size() - 2 && nums.at(i) == nums.at(i + 1)) ++i;
        }
        return sum;
    }
};
