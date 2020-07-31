/*
 * There is a one-dimensional garden on the x-axis. The garden starts at the
 * point 0 and ends at the point n. (i.e The length of the garden is n).
 *
 * There are n + 1 taps located at points [0, 1, ..., n] in the garden.
 *
 * Given an integer n and an integer array ranges of length n + 1 where
 * ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i
 * + ranges[i]] if it was open.
 *
 * Return the minimum number of taps that should be open to water the whole
 * garden, If the garden cannot be watered return -1.
 *
 * Date: 07/30/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  int ret{INT_MAX};
  int tapused;
  int numgarden;
  unordered_set<string> uset;

  // consider left part is covered
  void cover(const vector<int>& ranges, int start, int coveredtill) {
    if (tapused >= ret) return;
    string key{std::to_string(tapused) + "_" + std::to_string(start) + "_" +
               std::to_string(coveredtill)};
    if (uset.count(key)) return;

    if (coveredtill >= numgarden) {
      ret = ret > tapused ? tapused : ret;
      return;
    }

    for (int i = start; i < ranges.size(); ++i) {
      if (ranges[i] == 0) continue;
      if (ranges[i] + i > coveredtill && i - ranges[i] <= coveredtill) {
        ++tapused;
        cover(ranges, i + 1, ranges[i] + i);
        --tapused;
      }
    }
    uset.insert(key);
  }

 public:
  int minTaps(int n, vector<int>& ranges) {
    numgarden = n;
    tapused = 0;
    cover(ranges, 0, 0);
    return ret == INT_MAX ? -1 : ret;
  }
};

class Solution2 {
  int ret{INT_MAX};
  int tapused;
  int numgarden;
  vector<vector<int>> dp;

  // consider left part is covered
  int cover(const vector<int>& ranges, int start, int coveredtill) {
    if (dp[start][coveredtill] != -1) return dp[start][coveredtill];

    int ret{INT_MAX};
    if (coveredtill >= numgarden) {
      ret = ret > tapused ? tapused : ret;
      return 0;
    }

    for (int i = start; i < ranges.size(); ++i) {
      if (ranges[i] == 0) continue;
      if (ranges[i] + i > coveredtill && i - ranges[i] <= coveredtill) {
        ++tapused;
        auto up = cover(ranges, i + 1, ranges[i] + i);
        if (up > 0) ret = std::min(ret, up);
        --tapused;
      }
    }
    dp[start][coveredtill] = ret;
    return ret;
  }

 public:
  int minTaps(int n, vector<int>& ranges) {
    dp.resize(n + 1, vector<int>(n + 1, -1));
    numgarden = n;
    tapused = 0;
    return cover(ranges, 0, 0);
  }
};

class Solution3 {
 public:
  int minTaps(int n, vector<int>& r) {
    // dp[i] is the min number of tapes to water area from 0 to i
    vector<int> dp(n + 1, n + 2);  // Initialize with max
    dp[0] = 0;  // minimum tapes needed to water area 0 is 0(basically no area)
    for (int i = 0; i <= n; i++) {
      int left = max(0, i - r[i]);  // find the minimum point of garden(area) to
                                    // water with tape i.
      int right = min(n, i + r[i]);  // find the maximum point of garden(area)
                                     // to water with tape i.
      for (int j = left + 1; j <= right; j++) {
        // Check if this range from(left..right) can be watered using less
        // number of tapes than previous
        dp[j] = min(dp[j], dp[left] + 1);
      }
    }

    // If mimimum tapes needed to water area 0..n is greater than n , it means
    // we could not found minimum number of tapes
    if (dp[n] >= n + 2) return -1;
    return dp[n];
  }
};
