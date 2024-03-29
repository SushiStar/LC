/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log(m+n)). You may assume nums1 and nums2 cannot be both empty.
 *
 * Date: 05/15/2022
 * Author: Wei Du
 */

#include <vector>
using namespace std;

/**
 * @brief Considering two arrays in general case: v1, v2
 * The median value must exist and such that v1 v2 are cut into two halfs
 *
 *  ---------------------------------
 *  | | | | |v1[a]|v1[a+1]| | | | | |  v1
 *  ---------------------------------
 *
 *  ----------------------------------
 *  | | | | |v2[b]|v2[b+1] | | | | | |  v2
 *  ----------------------------------
 *
 * where {v1[0]->v1[a], v2[0]->v2[b]} represent the left half of the whole
 * partition;
 *
 * Then we have v1[a] <= v2[b+1], v2[b] <= v1[a+1]
 *
 * you need to use binary search approach to find the a,b positions that
 * satisfies this condition.
 *
 */
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);
    int total = nums1.size() + nums2.size();
    bool even{total % 2 == 0};
    if (nums1.empty()) {
      if (even) return (nums2[total / 2 - 1] + nums2[total / 2]) / 2.0;
      return nums2[total / 2];
    }
    nums1.insert(nums1.begin(), INT_MIN);
    nums2.insert(nums2.begin(), INT_MIN);
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);

    total += 4;
    int half{total / 2 - 2};
    int left1{0};
    int right1{(int)nums1.size() - 1};
    int mark1, mark2;
    while (true) {
      mark1 = (left1 + right1) / 2;
      mark2 = half - mark1;
      if (nums1[mark1] <= nums2[mark2 + 1]) {
        if (nums2[mark2] < nums1[mark1 + 1]) {
          break;
        }
        left1 = mark1 + 1;
      } else {
        right1 = mark1 - 1;
      }
    }

    int max_left = std::max(nums1[mark1], nums2[mark2]);
    int min_right = std::min(nums1[mark1 + 1], nums2[mark2 + 1]);
    if (even) return (max_left + min_right) / 2.0;
    return min_right;
  }
};
