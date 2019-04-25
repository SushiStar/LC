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
 * 3, If p.charAt(j) == '*':
 * here are two sub conditions:
 *      1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this
 * case, a* only counts as empty 2   if p.charAt(j-1) == s.charAt(i) or
 * p.charAt(j-1) == '.': dp[i][j] = dp[i-1][j]    //in this case, a* counts as
 * multiple a or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
 *          or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
 *
 * Date: Apr/25/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for (int i = 1; i <= m; i++) f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and
        // p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    f[i][j] = f[i - 1][j - 1] &&
                              (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                } else {
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] ||
                              (s[i - 1] == p[j - 2] || '.' == p[j - 2]) &&
                                  f[i - 1][j];
                }
            }
        }
        return f[m][n];
    }
};
