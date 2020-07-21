/*
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 * Date: 07/20/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
   vector<int> singleNumber(vector<int>& nums) {
     if (nums.size() == 2) return nums;
     vector<int> ret{0,0};
     int buffer{0};
     for (int n : nums)
       buffer ^= n;
     int lowtstsetbit;
     for (int i = 0; i < 32; ++i)
       if (buffer & (1 << i)) {
         lowtstsetbit = i;
         break;
       }
     for (int n : nums) {
       if (n & (1 << lowtstsetbit)) {
         ret[0] ^= n;
       } else {
         ret[1] ^= n;
       }
     }
     return ret;
   }
};
