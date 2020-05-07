/*
 * Given a 2D matrix, find the sum of the elements inside the rectangle 
 * defined by its upper left corner (row1, col1) and lower right 
 * corner (row2, col2).
 * The matrix is only modifiable by the update function.
 * You may assume the number of calls to update and sumRegion is distributed
 * evenly.
 * You may assume that row1 <= row2 and col1 <=col2.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : mtx(std::move(matrix)) {
        if (mtx.empty() || mtx[0].empty()) {
            numRow = -1;
            numCol = -1;
        } else {
            numRow = mtx.size();
            numCol = mtx[0].size();
        }
    }
    
    void update(int row, int col, int val) {
        if (row >= numRow || row < 0 || col >= numCol || col < 0)
            return;
        mtx[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (numRow < 0) return -1;
        int left(std::max(0, col1));
        int right(std::min(numCol-1, col2));
        int up(std::max(0, row1));
        int down(std::min(numRow-1, row2));
        int ret{0};
        for (int i = up; i <= down; ++i) 
            for (int j = left; j <= right; ++j)
                ret += mtx[i][j];
        return ret;
    }
private:
    std::vector<std::vector<int>> mtx;
    int numRow;
    int numCol;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
