/*
 * Write an efficient algorithm that searches for a value in
 * an m x n matrix. This matrix has the following properties:
 *  Integers in each row are sorted in ascending from left to right.
 *  Integers in each column are sorted in ascending from top
 *  to bottom.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || target < matrix[0][0] ||
            target > matrix.back().back())
            return false;
        int i(matrix.size() - 1);
        int j(0);
        while (i > -1 && j < matrix[0].size()) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++j;
            else
                --i;
        }
        return false;
    }
};
