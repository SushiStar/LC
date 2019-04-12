/*
 * Write an efficient algorithm that searches for a value in an
 * m x n matrix. This matrix has the following properties: Integers
 * in each row are sorted in ascending from left to right. Integers
 * in each column are sorted in ascending from top to bottom.
 *
 * Date: Apr/12/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int column = matrix[0].size();
        int row = matrix.size();
        int i(0), j(column - 1);
        while (i < row && j > -1) {
            if (matrix[i][j] == target) return true;
            matrix[i][j] > target ? --j : ++i;
        }
        return false;
    }
};
