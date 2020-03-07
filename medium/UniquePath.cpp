/*
 * A robot is located at the top-left corner of a mxn grid
 * 
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid.
 * How many possible unique paths are there? 
 *
 * Date: 03/07/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        size_t result{1};
        for (int i = 0; i < n-1; ++i) {
            result = result*(m+i)/(i+1);
        }
        return result;
    }
};
