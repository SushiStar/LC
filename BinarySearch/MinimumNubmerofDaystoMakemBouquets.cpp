/*
 * Given an integer array bloomDay, an integer m and an integer k.
 * We need to make m bouquets. To make a bouquet, you need to use k adjacent
 * flowers from the garden. The garden consists of n flowers, the ith flower
 * will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
 * Return the minimum number days you need to wait to be able make m bouquets
 * from the garden. If it is impossible to make m bouquets return -1.
 *
 * Date: 06/13/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
 public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n(bloomDay.size()), left{1}, right{(int)1e9};
    int mid = left + (right - left) / 2;
    if (m * k > n) return -1;
    while (left < right) {
      int flow(0), bouq(0);
      for (int j = 0; j < n; ++j) {
        if (bloomDay[j] > mid) {
          flow = 0;
        } else if (++flow == k) {
          ++bouq;
          flow = 0;
        }
      }
      if (bouq < m) {
        left = mid + 1;
      } else {
        right = mid;
      }
      mid = (right - left) / 2 + left;
    }
    return left;
  }
};

/*
 * Sample:
 * [1, 10, 3, 10, 2], m = 3, k = 2
 * [7, 7, 7, 7, 12, 7, 7], m = 2, k = 3
 * [100000000000, 100000000000], m = 1, k = 1
 * [1, 10, 2, 9, 3, 8, 4, 7, 5, 6], m = 4, k = 2
 *
 * Similar Binary Search problems:
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * https://leetcode.com/problems/koko-eating-bananas/
 * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
 */