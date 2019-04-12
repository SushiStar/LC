/*
 * Given a 2D binary matrix filled with 0's and 1's, find the
 * largest square containing only 1's and return its area.
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size()));
        int column = matrix[0].size();
        int row = matrix.size();

        int maxx(dp[0][0]);
        for (int i = 0; i < column; ++i) {
            dp[0][i] = matrix[0][i] == '1' ? 1:0;
            maxx = max(maxx, dp[0][i]);
        }
        for (int i = 0; i < row; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1:0;
            maxx = max(maxx, dp[i][0]);
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j])+1;
                    maxx = max(maxx, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxx;
    }
};
