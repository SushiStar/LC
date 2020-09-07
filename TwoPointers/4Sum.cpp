/*
 * Given an array nums of n integers and an integer target,
 * are there elements a,b,c and d in nums such that a+b+c+d=target?
 * Find all quadruplets in the array which gives the sum of target.
 *
 * Date: 03/09/2020
 *
 * Author: Wei Du
 *
 */
#include "../common.h"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    std::vector<std::vector<int>> result{};
    if (nums.size() <= 3) return result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int left{j + 1}, right(nums.size() - 1);
        while (left < right) {
          auto total = nums[i] + nums[j] + nums[left] + nums[right];
          if (total == target) {
            result.push_back(
                std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
            ++left;
            --right;
            while (left < right && nums[right] == nums[right + 1]) --right;
            while (left < right && nums[left] == nums[left - 1]) ++left;
          } else if (total > target) {
            --right;
          } else {
            ++left;
          }
        }
      }
    }
    return result;
  }
};
