/*
 * Given a matrix of m x n elements, return all elements in the matrix
 * in sprial order.
 *
 * Date: Apr/26/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int row(matrix.size()), column(matrix[0].size());
        // figure out the level
        int k = std::min(row / 2, column / 2);

        for (int i = 0; i < k; ++i) {
            int r1(i), r2(row - i - 1), c1(i), c2(column - i - 1);
            // traverse upper row
            for (int j = c1; j <= c2; ++j) {
                res.push_back(matrix[r1][j]);
            }
            // traverse right column
            for (int j = r1 + 1; j < r2; ++j) {
                res.push_back(matrix[j][c2]);
            }
            // traverse bottom row
            for (int j = c2; j >= c1; --j) {
                res.push_back(matrix[r2][j]);
            }
            // traverse left column
            for (int j = r2 - 1; j > r1; --j) {
                res.push_back(matrix[j][c1]);
            }
        }
        if (row >= column && column % 2) {
            int r1(k), r2(row - k - 1);
            int c(column / 2);
            for (int j = r1; j <= r2; ++j) {
                res.push_back(matrix[j][c]);
            }
        }
        if (row < column && row % 2) {
            int c1(k), c2(column - k - 1);
            int r(row / 2);
            for (int j = c1; j <= c2; ++j) {
                res.push_back(matrix[r][j]);
            }
        }
        return res;
    }
};
