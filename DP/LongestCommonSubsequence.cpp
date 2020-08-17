/*
 * Given two strings text1 and text2, return the length of
 * their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from
 * the original string with some characters (can be none)
 * deleted without changing the relative order of the remaining
 * characters. (eg, "ace" is a subsequence of "abcde" while
 * "aec" is not). A common subsequence of two strings is a
 * subsequence that is common to both strings.
 *
 * If there is no common subsequence, return 0.
 *
 * Date: 04/26/2020
 * Author: Wei Du
 */
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    std::vector<std::vector<int>> dp(text1.size() + 1,
                                     std::vector<int>(text2.size() + 1, 0));
    for (int i = 0; i < text1.size(); ++i) {
      for (int j = 0; j < text2.size(); ++j) {
        if (text1[i] == text2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp.back().back();
  }
};
