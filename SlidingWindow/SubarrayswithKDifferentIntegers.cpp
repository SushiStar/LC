/*
 * Given an array A of positive integers, call a (contiguous, not necessarily
 * distinct) subarray of A good if the number of different integers in that
 * array is exactly K.
 *
 * Return the number of good subarrays of A.
 *
 * Date: 07/10/2020
 * Author: Wei Du
 */
#include "../common.h"
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    return atMostKNumbers(A, K) - atMostKNumbers(A, K - 1);
  }

 private:
  int atMostKNumbers(const vector<int>& A, int K) {
    int left{0}, right{0}, res{0};
    unordered_map<int, int> mapp;
    while (right < A.size()) {
      if (mapp[A[right]]++ == 0) --K;  // new element
      while (K < 0) {  // more than K element in [i, j]
        if (--mapp[A[left]] == 0) ++K;
        ++left;
      }
      // pay attention to the following:
      res += right - left + 1;
      ++right;
    }
    return res;
  }
};
