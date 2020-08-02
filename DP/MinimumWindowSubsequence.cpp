/*
 * Given strings S and T, find the minimum (contiguous) substring W of S, so
 * that T is a subsequence of W.
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "". If there are multiple such minimum-length windows, return
 * the one with the left-most starting index.
 *
 * Date: 07/31/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
  string minWindow(string S, string T) {
    std::vector<vector<int>> dp(S.size(), vector<int>(T.size(), -1));
    for (int i = 0; i < S.size(); ++i)
      if (S[i] == T[0]) dp[i][0] = i;

    for (int j = 1; j < T.size(); ++j) {
      int k = -1;
      for (int i = 1; i < S.size(); ++i) {
        if (dp[i - 1][j - 1] > -1) k = dp[i - 1][j - 1];
        if (k != -1 && S[i] == T[j]) dp[i][j] = k;
      }
    }
    int len(INT_MAX), start;
    int Tlen(T.size() - 1);

    for (int i = 0; i < S.size(); ++i) {
      if (dp[i][Tlen] > -1 && i - dp[i][Tlen] < len) {
        len = i - dp[i][Tlen];
        start = dp[i][Tlen];
      }
    }

    return len == INT_MAX ? "" : S.substr(start, len + 1);
  }
};

class Solution2 {
 public:
  string minWindow(string S, string T) {
    vector<int> dp(S.size(), -1);
    for (int i = 0; i < S.size(); ++i)
      if (S[i] == T[0]) dp[i] = i;

    for (int j = 1; j < T.size(); ++j) {
      int k = -1;
      vector<int> dptmp(S.size(), -1);
      for (int i = 1; i < S.size(); ++i) {
        if (dp[i - 1] > -1) k = dp[i - 1];
        if (k != -1 && S[i] == T[j]) dptmp[i] = k;
      }
      std::swap(dptmp, dp);
    }
    int len(INT_MAX), start;
    int Tlen(T.size() - 1);

    for (int i = 0; i < S.size(); ++i) {
      if (dp[i] > -1 && i - dp[i] < len) {
        len = i - dp[i];
        start = dp[i];
      }
    }

    return len == INT_MAX ? "" : S.substr(start, len + 1);
  }
};

class Solution3 {
 public:
  string minWindow(string S, string T) {
    int sidx{0}, tidx{0};
    int start, len{INT_MAX};
    while (sidx < S.size()) {
      if (S[sidx] == T[tidx]) ++tidx;

      // matched;
      if (tidx == T.size()) {
        --tidx;
        int end = sidx;
        while (tidx > -1) {
          while (S[sidx] != T[tidx]) --sidx;
          --tidx;
          --sidx;
        }
        ++sidx;
        if (end - sidx + 1 < len) {
          len = end - sidx + 1;
          start = sidx;
        }
        tidx = 0;
      }
      ++sidx;
    }
    return len == INT_MAX ? "" : S.substr(start, len);
  }
};
