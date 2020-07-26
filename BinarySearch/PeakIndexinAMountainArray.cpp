/**
 * Let's call an array A a mountain if the following properties hold:
 *    A.length >= 3
 *    There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1]
 * < A[i] > A[i+1] > ... > A[A.length - 1] Given an array that is definitely a
 * mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] >
 * ... > A[A.length - 1].
 *
 * Note:
 *    3 <= A.length <= 10000
 *    0 <= A[i] <= 10^6
 *    A is a mountain, as defined above.
 *
 * Date: 07/26/2020
 * Author: Wei Du
 */

#include "../common.h"
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    A.push_back(INT_MIN);
    A.insert(A.begin(), INT_MIN);
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1] && A[i] > A[i + 1]) return i - 1;
    }
    return -1;
  }
};

class Solution2 {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int left(0), right(A.size()), mid(0);
    while (left < right) {
      mid = (right - left) / 2 + left;
      if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
        left = mid + 1;
      } else if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1]) {
        right = mid;
      } else {
        return mid;
      }
    }
    return mid;
  }
};
