/*
 * Given a non-empty 2D array of 0's and 1's, and island is a group
 * of 1's connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If
 * there is no island, the maximum area is 0.)
 *
 * Date: 04/01/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxArea{0};
        if (grid.size() == 0 || grid[0].size() == 0) return maxArea;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                int currArea{0};
                int x1{0}, x2{0}, y1{0}, y2{0};
                std::stack<coord> stk{};
                stk.push(coord{i, j});
                grid[i][j] = 0;
                while (!stk.empty()) {
                    auto pt = stk.top();
                    stk.pop();
                    ++currArea;

                    x1 = pt[0] - 1;
                    x2 = pt[0] + 1;
                    y1 = pt[1] - 1;
                    y2 = pt[1] + 1;
                    if (x1 > -1 && grid[x1][pt[1]] == 1) {
                        grid[x1][pt[1]] = 0;
                        stk.push(coord{x1, pt[1]});
                    }
                    if (x2 < grid.size() && grid[x2][pt[1]] == 1) {
                        grid[x2][pt[1]] = 0;
                        stk.push(coord{x2, pt[1]});
                    }
                    if (y1 > -1 && grid[pt[0]][y1] == 1) {
                        grid[pt[0]][y1] = 0;
                        stk.push(coord{pt[0], y1});
                    }
                    if (y2 < grid[0].size() && grid[pt[0]][y2] == 1) {
                        grid[pt[0]][y2] = 0;
                        stk.push(coord{pt[0], y2});
                    }
                }
                maxArea = std::max(maxArea, currArea);
            }
        }
        return maxArea;
    }

private:
    typedef std::array<int, 2> coord;
};
