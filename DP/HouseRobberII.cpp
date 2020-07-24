/*
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Date: 07/23/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
    int rob(vector<int>& nums) {
      assert(nums.size() < 5000);
      if (nums.empty()) return 0;
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return std::max(nums[0], nums[1]);
      return std::max(rob(nums, 0), rob(nums,1));
    }
private:
    int rob(vector<int> &nums, int start) {
      int end{(int)nums.size()-1};
      int pre{0}, cur{0};
      if (start == 0) --end;
      for (int i = start; i <= end; ++i) {
        int tmp = std::max(cur, pre + nums[i]);
        pre = cur;
        cur = tmp;
      }
      return cur;
    }
};
