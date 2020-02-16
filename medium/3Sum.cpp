/*
 * Given an array nums of n integers, are there a, b, c in nums
 * Such that a+b+c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Similar to 2sum method, fix one and find the rest two(sort and find sum of 2
 * ends). No need to look back because that situation is already consisdered.
 *
 * Date: 02/16/2020
 *
 * Autor: Wei Du
 *
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};

        if (nums.size() < 3) return res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int goal = -nums.at(i);
            int l(i + 1);
            int r(nums.size() - 1);
            while (l < r) {
                if (nums.at(l) + nums.at(r) == goal) {
                    vector<int> temp{nums.at(i), nums.at(l), nums.at(r)};
                    res.push_back(temp);

                    while (l < r && temp.at(2) == nums.at(r))
                        --r;
                    while (l < r && temp.at(1) == nums.at(l))
                        ++l;

                } else if (nums.at(l) + nums.at(r) > goal) {
                    --r;
                } else { // nums.at(l) + nums.at(r) < goal
                    ++l;
                }
            }
            // take the first of the repeated number, it has a larger solution
            // set than later repeated numbers
            while (i < nums.size() - 2 && nums.at(i) == nums.at(i + 1))
                ++i;
        }
        return res;
    }
};
