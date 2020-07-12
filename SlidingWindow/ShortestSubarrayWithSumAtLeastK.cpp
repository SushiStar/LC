/*
 * Return the length of the shortest, non-empty, contiguous subarray of A with
 * sum at least K. If there is no non-empty subarray with sum at least K, return
 * -1.
 *
 * Date: 07/10/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    int sum{0}, ret{INT_MAX};
    deque<int> dq{0};
    if (A[0] >= K ) return 1;
    for (int i = 1; i < A.size(); ++i) {
      A[i] += A[i-1];
      if (A[i] >= K) ret = std::min(ret, i + 1);
      while (!dq.empty() && A[i] - A[dq.front()] >= K) {
        ret = std::min(ret, i - dq.front());
        dq.pop_front();
      }
      while (!dq.empty() && A[i] <= A[dq.back()]) dq.pop_back();
      dq.push_back(i);
    }
    return ret == INT_MAX ? -1 : ret;
  }
};
