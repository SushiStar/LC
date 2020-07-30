/*
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 *
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 *
 * Date: 07/29/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  using ii = pair<int, int>;
  const int MOD = 1e9 + 7;

 public:
  int sumSubarrayMins(vector<int>& A) {
    std::vector<int> left(A.size());
    std::vector<int> right(A.size());
    std::vector<ii> stk;
    for (int i = 0; i < A.size(); ++i) {
      // others strictly larger than A[i]
      int count{1};
      while (!stk.empty() && stk.back().first > A[i]) {
        count += stk.back().second;
        stk.pop_back();
      }
      stk.push_back({A[i], count});
      left[i] = count;
    }
    stk.clear();
    for (int i = A.size() - 1; i > -1; --i) {
      int count{1};
      // consider others equal to A[i]
      while (!stk.empty() && stk.back().first >= A[i]) {
        count += stk.back().second;
        stk.pop_back();
      }
      stk.push_back({A[i], count});
      right[i] = count;
    }
    int ret{0};
    for (int i = 0; i < A.size(); ++i)
      ret = (ret + A[i] * left[i] * right[i]) % MOD;
    return ret;
  }
};
