/*
 * Given a 2d grid map of 1's and 0's, count the number of islands.
 * An island is surrounded by water and formed by connecting adjacent
 * islands vertically and horizentally. You may assume all four edges
 * of the edges are surrounded by water.
 *
 * Date: 03/24/2020
 * Author: Wei Du
 */
#include <numeric>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    // BFS
    int numIslands(std::vector<std::vector<char>> &grid) {
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

class Solution1 {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int result{0};
        // DO BFS
        std::stack<std::pair<int, int>> stk;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    stk.push(std::make_pair(i, j));
                    int x1{0}, x2{0}, y1{0}, y2{0};
                    while (!stk.empty()) {
                        auto coord = stk.top();
                        stk.pop();
                        grid[coord.first][coord.second] = '0';
                        y1 = coord.first - 1;
                        y2 = coord.first + 1;
                        x1 = coord.second - 1;
                        x2 = coord.second + 1;
                        // up
                        if (y1 > -1 && grid[y1][coord.second] == '1')
                            stk.push(std::make_pair(y1, coord.second));
                        // down
                        if (y2 < grid.size() && grid[y2][coord.second] == '1')
                            stk.push(std::make_pair(y2, coord.second));
                        // left
                        if (x1 > -1 && grid[coord.first][x1] == '1')
                            stk.push(std::make_pair(coord.first, x1));
                        // right
                        if (x2 < grid[0].size() && grid[coord.first][x2] == '1')
                            stk.push(std::make_pair(coord.first, x2));
                    }
                }
            }
        }
        return result;
    }
};

// union find
class Solution2 {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        row = grid.size();
        col = grid[0].size();
        parent.resize(row * col);
        std::iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0') continue;
                if (i > 0 && grid[i - 1][j] == '1') uni(i, j, i - 1, j);
                if (j > 0 && grid[i][j - 1] == '1') uni(i, j, i, j - 1);
            }
        }

        int ret{0};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != '0' && getParent(i, j) == i * col + j) {
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    int row, col;
    std::vector<int> parent;
    int getParent(int r, int c) {
        int idx = r * col + c;
        while (parent[idx] != idx) {
            idx = parent[idx];
        }
        return idx;
    }

    void uni(int r1, int c1, int r2, int c2) {
        int parent1 = getParent(r1, c1);
        int parent2 = getParent(r2, c2);
        if (parent1 != parent2) {
            parent[parent1] = parent2;
        }
    }
};
