/*
 * A robot is located at the top-left corner of a m x n grid.
 * The robot can move either down or right at any point in time. The robot is
 * trying to reach the bottom-right corner of the grid. Now consider if some
 * obstacles are added to the grids. How many unique paths would there be?
 *
 * Date: 03/11/2020
 * Author: Wei Du
 *
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int row(obstacleGrid.size());
        int column(obstacleGrid[0].size());
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][column - 1] == 1)
            return 0;
        std::vector<std::vector<long int>> dp(row,
                                              std::vector<long int>(column, 0));
        dp[0][0] = 1;
        for (int i = 1; i < row; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
        }
        for (int j = 1; j < column; ++j) {
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < column; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};
