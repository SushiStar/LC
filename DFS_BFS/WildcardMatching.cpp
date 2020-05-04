/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 *
 * Date: 05/04/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        std::vector<std::vector<bool>> dp(s.size()+1, std::vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for (int i = 0; i < p.size(); ++i) 
            if (p[i] == '*') dp[0][i+1] = true;
            else break;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == '?') {
                    dp[i+1][j+1] = dp[i][j];
                } else if (p[j] == '*') {
                    dp[i+1][j+1] = (dp[i][j] || dp[i][j+1] || dp[i+1][j]);
                } else {
                    dp[i+1][j+1] = (s[i] == p[j] && dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};
