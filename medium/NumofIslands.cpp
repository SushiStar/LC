/*
 * Given a 2d grid map of 1's and 0's, count the number of islands.
 * An island is surrounded by water and formed by connecting adjacent
 * islands vertically and horizentally. You may assume all four edges
 * of the edges are surrounded by water.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    // BFS
    int numIslands(vector < vector<char> & grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        int column = grid[0].size();
        int row = grid.size();

        int res(0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == '0') continue;
                // grid[i][j] == '1'
                ++res;
                std::queue<std::pair<int, int>> q;
                q.push(std::make_pair(i, j));
                grid[i][j] = '0';
                while (!q.empty()) {
                    auto m = q.front().first;
                    auto n = q.front().second;
                    if (m - 1 >= 0 && grid[m - 1][n] == '1') {
                        q.push(std::make_pair(m - 1, n));
                        grid[m - 1][n] = '0';
                    }
                    if (m + 1 < row && grid[m + 1][n] == '1') {
                        q.push(std::make_pair(m + 1, n));
                        grid[m + 1][n] = '0';
                    }
                    if (n - 1 >= 0 && grid[m][n - 1] == '1') {
                        q.push(std::make_pair(m, n - 1));
                        grid[m][n - 1] = '0';
                    }
                    if (n + 1 < column && grid[m][n + 1] == '1') {
                        q.push(std::make_pair(m, n + 1));
                        grid[m][n + 1] = '0';
                    }
                    q.pop();
                }
            }
        }
        return res;
    }
};
