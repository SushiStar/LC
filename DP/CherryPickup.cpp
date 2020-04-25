/*
 * In a NXN grid representing a field of cherries, each cell is one of
 * three possible integers.
 * 0 means the cell is empty, so you can pass through.
 * 1 means the cell contains a cherry, that you can pick up and pass through.
 * -1 means the cell contains a thorn that blocks your way.
 *
 * Your task is to collect maximum number of cherries possible by following
 * the rules below:
 *  Starting at position (0,0) and reaching (N-1, N-1) by moving right or down
 *  through valid path cells (cells with 0 or 1).
 *  After reaching (N-1, N-1), returning to (0,0) by moving left or up through
 *  valid path cells;
 *  When passing through a path cell containing a cherry, you pick it up and
 *  the cell becomes an empty cell (0);
 *  If there is no valid path between (0,0) and (N-1, N-1), then no cherries
 *  can be collected.
 *
 * Date: 04/25/2020
 * Author: Wei Du
 */

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int N = grid.size();
        int P_LEN = N + N - 1;
        vector<vector<int>> dp = vector<vector<int>>(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];

        for (int p = 2; p <= P_LEN; p++) { // p is the length of the path
            for (int x1 = N - 1; x1 >= 0; x1--) {
                for (int x2 = x1; x2 >= 0; x2--) {
                    int y1 = p - 1 - x1;
                    int y2 = p - 1 - x2;
                    if (y1 < 0 || y2 < 0 || y1 >= N || y2 >= N) continue;
                    if (grid[y1][x1] < 0 || grid[y2][x2] < 0) {
                        dp[x1][x2] = -1;
                        continue;
                    }
                    int best = -1, delta = grid[y1][x1];
                    if (x1 != x2) delta += grid[y2][x2];
                    if (x1 > 0 && x2 > 0 &&
                        dp[x1 - 1][x2 - 1] >= 0) // from left left
                        best = max(best, dp[x1 - 1][x2 - 1] + delta);
                    if (x1 > 0 && y2 > 0 && dp[x1 - 1][x2] >= 0) // from left up
                        best = max(best, dp[x1 - 1][x2] + delta);
                    if (y1 > 0 && x2 > 0 && dp[x1][x2 - 1] >= 0) // from up left
                        best = max(best, dp[x1][x2 - 1] + delta);
                    if (y1 > 0 && y2 > 0 && dp[x1][x2] >= 0) // from up up
                        best = max(best, dp[x1][x2] + delta);
                    dp[x1][x2] = best;
                }
            }
        }
        return dp[N - 1][N - 1] < 0 ? 0 : dp[N - 1][N - 1];
    }
};
