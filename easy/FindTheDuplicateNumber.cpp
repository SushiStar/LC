/*
 * Given an array nums containing n + 1 integers where each integer is between 1
 * and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        std::unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp[nums[i]]) return nums[i];
            ++mp[nums[i]];
        }
        return -1;
    }
};
