/*
 * In a given grid, each cell can have one of three values:
 *      the value 0 representing an empty cell;
 *      the value 1 representing a fresh orange;
 *      the value 2 representing a rotten orange.
 * Every minute, any fresh orange that is adjacent (4-directionally)
 * to a rotten orange becomes rotte.
 *
 * Return the minimum number of minutes that must elapse until
 * no cell has a fresh orange. If this is impossible, return -1 instead.
 *
 * Date: 05/14/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int ret{0};
        int row(grid.size());
        int col(grid[0].size());

        // do BFS
        std::vector<std::vector<int>> bfs_curr{};
        std::vector<std::vector<int>> bfs_next{};

        // get the first round rotten oranges
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) {
                    bfs_curr.push_back({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while (!bfs_curr.empty()) {
            for (auto &orange : bfs_curr) {
                // grid[orange[0]][orange[1]] = 0;
                if (orange[0] > 0 && grid[orange[0] - 1][orange[1]] == 1) {
                    grid[orange[0] - 1][orange[1]] = 0;
                    bfs_next.push_back({orange[0] - 1, orange[1]});
                }
                if (orange[0] < row - 1 &&
                    grid[orange[0] + 1][orange[1]] == 1) {
                    grid[orange[0] + 1][orange[1]] = 0;
                    bfs_next.push_back({orange[0] + 1, orange[1]});
                }
                if (orange[1] > 0 && grid[orange[0]][orange[1] - 1] == 1) {
                    grid[orange[0]][orange[1] - 1] = 0;
                    bfs_next.push_back({orange[0], orange[1] - 1});
                }
                if (orange[1] < col - 1 &&
                    grid[orange[0]][orange[1] + 1] == 1) {
                    grid[orange[0]][orange[1] + 1] = 0;
                    bfs_next.push_back({orange[0], orange[1] + 1});
                }
            }
            ++ret;
            bfs_curr.clear();
            std::swap(bfs_curr, bfs_next);
        }

        // check the grid if it still contain any fresh orange.
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return ret > 0 ? --ret : 0;
    }
};
