/*
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 *
 * Date: 06/13/2020
 * Author: Wei Du
 */
#include <limits>
#include <string>
#include <vector>
using namespace std;

using vi = vector<int>;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        vector<vi> dp(word1.size() + 1, vi(word2.size() + 1, 0));
		for (int i = 0; i < word1.size(); ++i) dp[i][0] = i;
		for (int i = 0; i < word2.size(); ++i) dp[0][i] = i;
        for (int i = 0; i < word1.size(); ++i) {
            for (int j = 0; j < word2.size(); ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = std::min(dp[i + 1][j], std::min(dp[i][j], dp[i][j + 1])) + 1;
                }
            }
        }
        return dp.back().back();
    }
};
