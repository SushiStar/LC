/*
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 *
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e., one
 * or more connected land cells). The island doesn't have "lakes" (water inside
 * that isn't connected to the water around the island). One cell is a square
 * with side length 1. The grid is rectangular, width and height don't exceed
 * 100. Determine the perimeter of the island.
 *
 * Date: 03/31/2020
 * Author: Wei Du
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result{0};
        for (int i = 0; i < grid.size(); ++i ){
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0)
                    continue;
                result+= numWater(grid, i, j);
            }
        }
        return result;
    }
    
private:
    int numWater(const std::vector<std::vector<int>>& grid, int x, int y) {
        int x1(x-1);
        int x2(x+1);
        int y1(y-1);
        int y2(y+1);
        int result{0};
        if (x1 < 0 || grid[x1][y] == 0)
            ++result;
        if (x2 >= grid.size() || grid[x2][y] == 0)
            ++result;
        if (y1 < 0 || grid[x][y1] == 0) 
            ++result;
        if (y2 >= grid[0].size() || grid[x][y2] == 0)
            ++result;
        return result;
    }
};
