/*
 * Given an array of n integers nums and target, find the number of index
 * triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] +
 * nums[j] + nums[k] < target.
 *
 * Date: 07/20/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int end(nums.size() - 2), ret(0);
    for (int i = 0; i < nums.size(); ++i) {
      int left(i + 1), right(nums.size() - 1);
      int bound(target - nums[i]);
      while (left < right) {
        if (nums[left] + nums[right] >= bound) {
          --right;
        } else {
          ret += right - left;
          ++left;
        }
      }
    }
    return ret;
  }
};
