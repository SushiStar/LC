/*
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 *
 * Given an array nums, there is a sliding window of size k which is moving from
 * the very left of the array to the very right. You can only see the k numbers
 * in the window. Each time the sliding window moves right by one position. Your
 * job is to output the median array for each window in the original array.
 *
 * Note:
 *      You may assume k is always valid, ie: k is always smaller than input
 *      array's size for non-empty array.
 *      Answers within 10^-5 of the actual value will be accepted as correct.
 *
 * Date: 07/12/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ret{};
    multiset<int> mset(nums.begin(), nums.begin() + k);
    bool odd(k & 1);
    int left(0), right(k - 1);
    auto mid = std::next(mset.begin(), (k + 1) / 2 - 1);
    while (right < nums.size()) {
      if (odd)
        ret.push_back(*(mid));
      else
        ret.push_back(((double)*mid + *next(mid)) / 2.0);
      if (++right < nums.size()) {
        mset.insert(nums[right]);
        if (nums[right] < *mid) --mid;
      }
      if (nums[left] <= *mid) ++mid;
      mset.erase(mset.find(nums[left++]));
    }
    return ret;
  }
};
