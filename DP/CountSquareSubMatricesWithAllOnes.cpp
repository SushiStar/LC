/*
 * Given a m*n matrix of zeros and ones, return how many square submatrices 
 * have all ones.
 *
 * Date: 05/21/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ret(0);
        if (matrix.empty() || matrix[0].empty()) 
            return ret;
        std::vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            int width(0);
            for (int j = 0; j < height.size(); ++j) {
                if (matrix[i][j] == 0) {
                    width = 0;
                    height[j] = 0;
                } else {
                    ++width;
                    ++height[j];
                    if (i > 0 && j > 0) {
                        matrix[i][j] = std::min(width, std::min(height[j], matrix[i-1][j-1]+1));
                    }
                    ret += matrix[i][j];
                }
            }
        }
        return ret;
    }
};
