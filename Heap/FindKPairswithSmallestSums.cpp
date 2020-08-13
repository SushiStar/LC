/*
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array. Find the k pairs (u1,v1),(u2,v2)
 * ...(uk,vk) with the smallest sums.
 *
 * Date: 08/12/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    int size1{(int)nums1.size()}, size2{(int)nums2.size()};
    k = std::min(k, size1 * size2);
    std::vector<int> indices(size1, 0);
    std::vector<std::vector<int>> ret(k);
    while (k-- > 0) {
      int tmpsum{INT_MAX}, tmpidx{0};
      for (int i = 0; i < size1; ++i) {
        if (indices[i] == size2) continue;
        if (nums1[i] + nums2[indices[i]] < tmpsum) {
          tmpsum = nums1[i] + nums2[indices[i]];
          tmpidx = i;
        }
      }
      ret[k].push_back(nums1[tmpidx]);
      ret[k].push_back(nums2[indices[tmpidx]]);
      indices[tmpidx]++;
    }
    return ret;
  }
};
