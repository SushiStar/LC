/*
 * Given an array of integers, find if the array contains any duplicates.
 * You function should return true if any value appears at least twice in
 * the array, and it should return false if every element is distinct.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.size() < 2) return false;
        std::unordered_set<int> sett{nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            if (sett.find(nums[i]) != sett.end())
                return true;
            else
                sett.insert(nums[i]);
        }
        return false;
    }
};
