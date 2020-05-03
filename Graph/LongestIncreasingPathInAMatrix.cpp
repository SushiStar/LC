/*
 * Given an integer matrix, find the length of the longest increasing path.
 * From each cell, you can either move to four directions: left, right, up
 * or down. You may NOT move diagonally or move outside of the boundary.
 *
 * Date: 05/02/2020
 * Author: Wei Du
 */

#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        depth.resize(matrix.size(), std::vector<int>(matrix[0].size(), -1));
        // Do BFS  with memo
        int ret{1};
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                coord curr{i, j};
                ret = std::max(ret, bfs(matrix, curr));
            }
        }
        return ret;
    }

private:
    typedef std::pair<int, int> coord;
    std::vector<std::vector<int>> depth;

    int bfs(const std::vector<std::vector<int>> &matrix, coord &curr) {
        if (depth[curr.first][curr.second] != -1)
            return depth[curr.first][curr.second];
        int ret{1};
        int row(curr.first), col(curr.second);
        int currVal{matrix[row][col]};
        if (row > 0 && matrix[row - 1][col] > currVal) {
            coord neighbor{row - 1, col};
            ret = std::max(ret, bfs(matrix, neighbor) + 1);
        }
        if (row < matrix.size() - 1 && matrix[row + 1][col] > currVal) {
            coord neighbor{row + 1, col};
            ret = std::max(ret, bfs(matrix, neighbor) + 1);
        }
        if (col > 0 && matrix[row][col - 1] > currVal) {
            coord neighbor{row, col - 1};
            ret = std::max(ret, bfs(matrix, neighbor) + 1);
        }
        if (col < matrix[0].size() - 1 && matrix[row][col + 1] > currVal) {
            coord neighbor{row, col + 1};
            ret = std::max(ret, bfs(matrix, neighbor) + 1);
        }
        depth[row][col] = ret;
         return ret;
    }
};
