/*
 * Given a non-empty 2D matrix and an integer k, find the max sum of a rectangle
 * in the matrix such that its sum is no larger than k.
 *
 * The rectangle inside the matrix must have an area > 0.
 * Date: 06/25/2020
 * Author: Wei Du
 */
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int ret{INT_MIN};
        int row(matrix.size()), col(matrix[0].size());
        for (int i = 0; i < row; ++i) {
            matrix[i].push_back(0);
            for (int j = col - 1; j > -1; --j) {
                matrix[i][j] += matrix[i][j + 1];
            }
        }
        std::set<int> visited{};
        for (int i = col; i > 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                visited.clear();
                visited.insert(0);
                int acc{0};
                for (int m = 0; m < row; ++m) {
                    acc += {matrix[m][j] - matrix[m][i]};
                    auto it = visited.lower_bound(acc - k);
                    if (it != visited.end()) {
                        ret = max(ret, acc - *it);
                    }
                    visited.insert(acc);
                }
            }
        }
        return ret;
    }
};
