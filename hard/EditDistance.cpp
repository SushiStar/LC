/*
 * Given 2 words word1 and word2, find the minimum number of
 * operations required to convert word1 to word2.
 *
 * You have the following 3 operations permitted to a word:
 * 1. Insert a character.
 * 2. Delete a character.
 * 3. Replace a character.
 *
 * Date: 03/08/2020
 *
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDisstance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> tp(n + 1, 0);
        vector<vector<int>> dp(m + 1, tp);

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) +
                        1;
                }
            }
        }
        return dp[m][n];
    }
};
