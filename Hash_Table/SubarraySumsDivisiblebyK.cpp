/*
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 *
 * Date: 08/13/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    unordered_map<int, int> cnt{{((A[0] % K) + K) % K, 1}};
    int ret = A[0] % K == 0 ? 1 : 0;
    for (int i = 1; i < A.size(); ++i) {
      A[i] += A[i - 1];
      ret += cnt[((A[i] % K) + K) % K]++;
      if (A[i] % K == 0) ++ret;
    }
    return ret;
  }
};
