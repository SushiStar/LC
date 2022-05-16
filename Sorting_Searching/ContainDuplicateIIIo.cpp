/*
 * Given an array of integers, find out whether there are two distinct indices i
 * and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most k
 *
 * Date: 06/28/2020
 * Author: Wei Du
 */

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// bucket sort
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    // k is idx gap, t is value diff
    if (t < 0 || k <= 0 || nums.size() < 2) return false;
    auto lh = std::minmax_element(nums.begin(), nums.end());
    long maxVal(*lh.second), minVal(*lh.first);
    long diff(maxVal - minVal);
    if (diff <= t) return true;
    long numBins = t <= 1 ? nums.size() : diff / t;
    long binSize = max(diff / numBins + 1, (long)1);
    numBins++;
    vector<int> bucket[numBins];  // to save their indices
    for (int i = 0; i < nums.size(); ++i) {
      int idx = (nums[i] - minVal) / binSize;
      bucket[idx].push_back(i);
    }

    int prev(-1);
    for (int i = 0; i < numBins; ++i) {
      if (bucket[i].empty())
        continue;
      else if (bucket[i].size() >
               1) {  // multiple numbers satisfy abs(a-b) <= t
        std::sort(bucket[i].begin(), bucket[i].end());
        int begin = prev == -1 ? 1 : 0;
        prev = prev == -1 ? bucket[i][0] : prev;
        for (int j = begin; j < bucket[i].size(); ++j) {
          if (bucket[i][j] - prev <= k &&
              abs((long)nums[bucket[i][j]] - nums[prev]) <= t) {
            return true;
          }
          prev = bucket[i][j];
        }
      } else {  // only one element here
        if (prev != -1 && nums[bucket[i][0]] - (long)nums[prev] <= t &&
            bucket[i][0] - prev <= k)
          return true;
        prev = bucket[i][0];
      }
    }
    return false;
  }

  bool containsNearbyAlmostDuplicate1(vector<int> &nums, int kk, int tt) {
    set<int> window;
    int k{kk}, t{tt};
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) window.erase(nums[i - k - 1]);
      auto pos = window.lower_bound(nums[i] - t);
      if (pos != window.end() && *pos - nums[i] <= t) return true;
      window.insert(nums[i]);
    }
    return false;
  }
};
