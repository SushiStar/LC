/*
 * Numbers can be regarded as product of its factors. For example,
 * 8 = 2 x 2 x 2;
 *   = 2 x 4.
 * Write a function that takes an integer n and return all possible combinations
 * of its factors.
 *
 * Note:
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 *
 * Date: 07/19/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  vector<vector<int>> ret;
  vector<int> base;
  int target;
  void compute(int n, int start) {
    for (int i = start; i * i <= n; ++i) {
      if (n % i == 0) {
        base.push_back(i);
        compute(n / i, i);
        base.pop_back();
      }
    }
    if (target != n) {
      base.push_back(n);
      ret.push_back(base);
      base.pop_back();
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    if (n <= 3) return {};
    target = n;
    compute(n, 2);
    return ret;
  }
};
