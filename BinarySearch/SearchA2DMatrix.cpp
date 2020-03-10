/**
 * Write an efficient algorithm that searches a value in an m x n matrix. This
 * matrix has the following properties:
 *      Integers in each row are sorted from left to right.
 *      The first integer of each row is greater than the last integer of the
 *      previous row.
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row(matrix.size() - 1);
        int column(matrix[0].size() - 1);

        // outer find
        if (target < matrix[0][0] || target > matrix[row][column]) return false;
        int uptr{0}, dptr{row};
        int midrow = (uptr + dptr) / 2;
        // take care of the last row
        if (target >= matrix[row][0]) {
            midrow = row;
        } else {
            while (uptr < dptr) {
                if (matrix[midrow][0] < target) {
                    uptr = midrow + 1;
                } else if (matrix[midrow][0] > target) {
                    dptr = midrow;
                } else {
                    return true;
                }
                midrow = (uptr + dptr) / 2;
            }
            --midrow;
        }

        // inner find
        if (target > matrix[midrow].back()) return false;
        int lptr{0}, rptr{column};
        int midcolumn = (lptr + rptr) / 2;
        while (lptr < rptr) {
            if (matrix[midrow][midcolumn] < target) {
                lptr = midcolumn + 1;
            } else if (matrix[midrow][midcolumn] > target) {
                rptr = midcolumn;
            } else {
                return true;
            }
            midcolumn = (lptr + rptr) / 2;
        }
        // take care of the end
        return matrix[midrow][midcolumn] == target;
    }
};
