/*
 * Given a m x n matrix, if an element is zero, set its entire
 * row and column to 0. Do it in-place.
 *
 * Date: Apr/27/2019
 * Author: Wei Du
 */
#include <vector>
#include <unordered_set>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int row(matrix.size()), column(matrix[0].size());
        std::unordered_set<int> r,c;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if(!matrix[i][j]) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for (auto& k : r) {
            for (int i = 0; i < column; ++i) {
                matrix[k][i] = 0;
            }
        }
        for (auto& k : c) {
            for (int i = 0; i < row; ++i) {
                matrix[i][k] = 0;
            }
        }
        return;
    }
};
