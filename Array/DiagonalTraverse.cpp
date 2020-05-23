/*
 * Given a matrix of M x N elements (M rows, N columns), return all 
 * elements of this matrix in diagonal orders.
 *
 *
 * Date: 05/22/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        std::vector<int> ret{};
        if (matrix.empty()) return ret;
        int row(matrix.size()), col(matrix[0].size());
        int end(row+col-1);
        for (int i = 0; i <= end; ++i) {
            if (i&1) { // odd
                for (int idx = 0; idx <= i; ++idx) {
                    ret.push_back(matrix[idx][i-idx]);
                }
            } else {    // even
                for (int idx = i; idx > -1; --idx) {
                    ret.push_back(matrix[idx][i-idx]);
                }
            }
        }
        return ret;
    }
};
