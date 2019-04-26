/*
 * Given an input string s and a pattern p, implement wild card pattern
 * matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? and *.
 *
 * Date: Apr/25/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        std::vector<std::vector<bool>> dp(
            s.size() + 1, std::vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); ++i)
            dp[0][i] = (p[i - 1] == '*') && dp[0][i - 1];
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == s[i] || p[j] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
