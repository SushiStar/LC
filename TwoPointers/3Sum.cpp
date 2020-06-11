/*
 * Given an array nums of n integers, are there a, b, c in nums
 * Such that a+b+c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Similar to 2sum method, fix one and find the rest two(sort and find sum of 2
 * ends). No need to look back because that situation is already consisdered.
 *
 * Date: 06/11/2020
 * Autor: Wei Du
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};

        if (nums.size() < 3) return res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int goal(-nums[i]), l(i + 1), r(nums.size() - 1);
            while (l < r) {
                if (nums[l] + nums[r] == goal) {
					int a(nums[i]), b(nums[l]), c(nums[r]);
                    res.push_back({a, b, c});
                    while (l < r && b == nums[l]) ++l;
                    while (l < r && c == nums[r]) --r;
                } else if (nums.at(l) + nums.at(r) > goal) {
                    --r;
                } else { // nums.at(l) + nums.at(r) < goal
                    ++l;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return res;
    }
};
