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
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int numRow(matrix.size());
        int numCol(matrix[0].size());
        std::vector<int> height(numCol,0);
        std::vector<int> leftBoundary(numCol,0);
        std::vector<int> rightBoundary(numCol , numCol- 1);
        int result{0};
        for (int i = 0; i < numRow; ++i) {
            int currLeftBoundary(0);
            int currRightBoundary(numCol - 1);
            for (int j = numCol - 1; j > -1; --j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                    rightBoundary[j] =
                        std::min(rightBoundary[j], currRightBoundary);
                } else {
                    height[j] = 0;
                    currRightBoundary = j - 1;
                    rightBoundary[j] = numCol - 1;
                }
            }

            for (int j = 0; j < numCol; ++j){
                if (matrix[i][j] == '1') {
                    leftBoundary[j] = std::max(leftBoundary[j], currLeftBoundary);
                } else {
                    leftBoundary[j] = 0;
                    currLeftBoundary = j+1;
                    continue;
                }
                result = std::max(result, (rightBoundary[j] - leftBoundary[j] +1) * height[j]);
            }
        }
        return result;
    }
};
