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
 *      1. if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this
 * case, a* only counts as empty
 *      2. if p.charAt(j-1) == s.charAt(i) or p.charAt(j-1) == '.': dp[i][j] =
 * dp[i-1][j]    //in this case, a* counts as multiple a or dp[i][j] =
 * dp[i][j-1]   // in this case, a* counts as single a or dp[i][j] = dp[i][j-2]
 * // in this case, a* counts as empty
 *
 * Date: Apr/25/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        // initialize table
        std::vector<std::vector<bool>> table(
            s.size() + 1, std::vector<bool>(p.size() + 1, false));
        table[0][0] = true;
        // table[0][1] = false;
        for (int j = 1; j < p.size(); ++j)
            table[0][j + 1] = table[0][j - 2] && p[j] == '*';
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == '*') {
                    table[i + 1][j + 1] =
                        table[i + 1][j - 2] ||
                        (table[i][j + 1] &&
                         (p[j - 1] == s[i] || p[j - 1] == '.'));
                } else {
                    table[i + 1][j + 1] =
                        table[i][j] && (p[j] == s[i] || p[j] == '.');
                }
            }
        }
        return table[s.size()][p.size()];
    }
};
