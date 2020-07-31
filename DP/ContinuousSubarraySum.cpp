/*
 * Given a list of non-negative numbers and a target integer k, write a function
 * to check if the array has a continuous subarray of size at least 2 that sums
 * up to a multiple of k, that is, sums up to n*k where n is also an integer.
 *
 * Date: 07/30/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
  // non-negative nums;
  bool checkSubarraySum(vector<int>& nums, int k) {
    int prevmod{0}, cursum{0};
    unordered_set<int> modk;
    for (int i = 0; i < nums.size(); ++i) {
      cursum += nums[i];
      int mod = k == 0 ? cursum : cursum % k;
      if (modk.count(mod)) return true;
      modk.insert(prevmod);
      prevmod = mod;
    }
    return false;
  }
};
