/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements
 * of the matrix in spiral order.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        std::vector<int> ret{};
        if (matrix.empty() || matrix[0].empty()) return ret;
        int up(0), down(matrix.size() - 1), left(0),
            right(matrix[0].size() - 1);
        while (up <= down && left <= right) {
            // up: left -> right
            for (int i = left; i <= right; ++i)
                ret.push_back(matrix[up][i]);
            ++up;
            // right: up -> down
            for (int i = up; i <= down; ++i)
                ret.push_back(matrix[i][right]);
            --right;
            // down: right -> left
            if (up <= down) {
                for (int i = right; i >= left; --i)
                    ret.push_back(matrix[down][i]);
                --down;
            }
            // left: down->up
            if (left <= right) {
                for (int i = down; i >= up; --i)
                    ret.push_back(matrix[i][left]);
                ++left;
            }
        }
        return ret;
    }
};
