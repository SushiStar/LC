/*
 * On a 2-dimensional grid, there are 4 types of squares:
 *  1 represents the starting square. There is exactly one starting square.
 *  2 represents the ending square. There is exactly one ending square.
 *  0 represents empty squares we can walk over.
 *  -1 represents obstacles that we cannot walk over.
 * Return the number of 4 directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 *
 * Date: 05/26/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++numOpen;
                } else if (grid[i][j] == 1){
                    startx = i;
                    starty = j;
                    ++numOpen;
                }
            }
        }
        dfsFrom(grid, startx, starty);
        return ret;
    }
private:
    int ret{0};
    int numOpen{0};

    void dfsFrom(std::vector<std::vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2 ) {
            if (numOpen == 0)
                ++ret; 
            return;
        }
        grid[x][y] = -1;
        --numOpen;
        // down
        if (x+1 < grid.size() && grid[x+1][y] != -1) {
            dfsFrom(grid, x+1, y);
        }
        // up
        if (x > 0 && grid[x-1][y] != -1) {
            dfsFrom(grid, x-1, y);
        }
        // left
        if (y > 0 && grid[x][y-1] != -1) {
            dfsFrom(grid, x, y-1);
        }
        // right
        if (y+1 < grid[0].size() && grid[x][y+1] != -1) {
            dfsFrom(grid, x, y+1);
        }

        grid[x][y] = 0;
        ++numOpen;
    }
};
