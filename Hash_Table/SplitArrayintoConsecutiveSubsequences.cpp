/*
 * Given an array nums sorted in ascending order, return true if and only if you
 * can split it into 1 or more subsequences such that each subsequence consists
 * of consecutive integers and has length at least 3.
 *
 * Date: 08/12/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
public:
  bool isPossible(vector<int> &nums) {
    std::unordered_map<int, int> count, end;
    for (int num : nums) count[num]++;
    for (int num : nums) {
      if (count[num] == 0) continue;
      --count[num];
      if (end[num - 1] > 0) {
        --end[num - 1];
        ++end[num];
      } else if (count[num + 1] > 0 && count[num + 2] > 0) {
        --count[num + 1];
        --count[num + 2];
        ++end[num + 2];
      } else {
        return false;
      }
    }
    return true;
  }
};
