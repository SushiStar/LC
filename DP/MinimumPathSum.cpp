/*
 * Given an mxn grid filled with non-negative numbers, find a path from
 * top-left to bottom right which minimizes the sum of all numbers along
 * it's path.
 *
 * You can only move either down or right at any point in time.
 *
 * Date: 03/07/2020
 *
 * Author: Wei Du
 *
 */

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        std::vector<int> m(col + 1, INT_MAX);
        std::vector<std::vector<int>> cost(row + 1, m);
        std::queue<std::pair<int, int>> q;

        cost[0][0] = grid[0][0];
        q.push(std::make_pair(0, 0));
        while (!q.empty()) {
            auto f = q.front();
            auto fcst = cost[f.first][f.second];
            q.pop();

            if (f.first < row) {
                auto pos = std::make_pair(f.first + 1, f.second);
                int tpcst = fcst + grid[pos.first][pos.second];
                if (tpcst < cost[pos.first][pos.second]) {
                    cost[pos.first][pos.second] = tpcst;
                    q.push(pos); // only push nodes could make contribution
                }
            }
            if (f.second < col) {
                auto pos = std::make_pair(f.first, f.second + 1);
                int tpcst = fcst + grid[pos.first][pos.second];
                if (tpcst < cost[pos.first][pos.second]) {
                    cost[pos.first][pos.second] = tpcst;
                    q.push(pos); // only push nodes could make contribution
                }
            }
        }
        return cost[row][col];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        std::vector<int> m(col + 1, INT_MAX);
        std::vector<std::vector<int>> cost(row + 1, m);
        cost[0][0] = grid[0][0];

        int sum = row + col;
        for (int op = 1; op <= sum; ++op) {

            int r(0), c(0);
            if (op > row) {
                r = row;
                c = op - row;
            }
            while (c <= col) {
                if (r > 0)
                    cost[r][c] = min(cost[r][c], cost[r - 1][c] + grid[r][c]);
                if (c > 0)
                    cost[r][c] = min(cost[r][c], cost[r][c - 1] + grid[r][c]);
                --r;
                ++c;
            }
        }
        return cost[row][col];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>&grid) {
        int col{grid[0].size()};
        int row{grid.size()};
        std::vector<std::vector<int>> rlt(row, std::vector<int>(col, INT_MAX));
        rlt[0][0] = grid[0][0];
        for (int i = 1; i < col; ++i)
            rlt[0][i] = rlt[0][i-1] + grid[0][i];
        for (int j = 1; j < row; ++j) 
            rlt[j][0] = rlt[j-1][0] + grid[j][0];
        for (int i= 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) 
                rlt[i][j] = std::min(rlt[i-1][j], rlt[i][j-1]) + grid[i][j];
        }
        return rlt[row-1][col-1];
    }
};
