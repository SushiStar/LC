/*
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice
 * in the array and it should return false if every element is distinct.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return true;
        std::unordered_map<int,int> mp;
        for (auto& num : nums) {
            if(mp[num]) return true;
            else ++mp[num];
        }
        return false;
    }
};

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
