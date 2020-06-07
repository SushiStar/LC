/*
 * Given a 2D binary matrix filled with 0's and 1's, find the
 * largest rectangle containing only 1's and return its area.
 *
 * Date: 03/30/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row(matrix.size()), col(matrix[0].size());
        int ret{0};
        vector<int> height(col, 0);
        vector<int> leftBound(col, -1);
        vector<int> rightBound(col, col);
        int currLeftBound(-1), currRightBound(col);
        for (int i = 0; i < row; ++i) {
            currLeftBound = -1;
            currRightBound = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                    leftBound[j] = std::max(leftBound[j], currLeftBound);
                } else { // invalid
                    currLeftBound = j;
                    leftBound[j] = -1;
                    height[j] = 0;
                }
            }
            for (int j = col - 1; j > -1; --j) {
                if (matrix[i][j] == '1') {
                    rightBound[j] = std::min(rightBound[j], currRightBound);
                    ret = std::max(ret, (rightBound[j] - leftBound[j] - 1) *
                                            height[j]);
                } else {
                    currRightBound = j;
                    rightBound[j] = col;
                }
            }
        }
        return ret;
    }
};
