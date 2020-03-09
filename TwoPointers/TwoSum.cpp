/*
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target. You may assume that each input would have
 * exactly one solution, and you may not use the the same element twice.
 *
 * Date: 03/09/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> num_idx;
        std::vector<int> rlt;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (num_idx.find(comp) == num_idx.end())
                num_idx[nums[i]] = i;
            else {
                rlt.push_back(i);
                rlt.push_back(num_idx[comp]);
                return rlt;
            }
        }
    }
};
