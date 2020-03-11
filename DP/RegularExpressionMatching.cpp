/*
 * Given an input string s and a pattern p, implement a regular expression
 * matching with support for '.' and '*'.
 *  '.' matches any single character.
 *  '*' matches zero or more of the preceding element.
 *  s could be empty or contains only lower case letters a-z.
 *  p could be empty or contains only lower case letters a-z and characters like
 * . and *.
 *
 * 1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
 * 2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
 * 3, If p.charAt(j) == '*': here are two sub conditions:
 *      1. if p.charAt(j-1) != s.charAt(i) :
 *          dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
 *      2. if p.charAt(j-1) == s.charAt(i) or p.charAt(j-1) == '.':
 *          dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
 *       or dp[i][j] = dp[i][j-1]    // in this case, a* counts as single a
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
        // dp[0][1] = false;
        for (int i = 1; i < p.size(); ++i) {
            dp[0][i + 1] = dp[0][i - 1] && p[i] == '*';
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == s[i] || p[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else if (p[j] == '*') {
                    dp[i + 1][j + 1] =
                        dp[i + 1][j - 1] ||
                        (dp[i + 1][j] || dp[i][j + 1]) &&
                            (p[j - 1] == '.' || p[j - 1] == s[i]);
                }
                // else dp[i+1][j+1] = false;
            }
        }
        return dp[s.size()][p.size()];
    }
};
