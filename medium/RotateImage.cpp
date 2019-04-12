/*
 * You are given an nxn 2D matrix representing an image,
 * Rotate the images by 90 degrees clockwise.
 *
 * You have to rotate the image in place, which means you have to
 * modify the input 2D matrix directly.
 * Do not allocate another 2D matrix and do the rotation.
 *
 * Date: Mar/29/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size()-1;
        if (sz <= 1) return;

        for (int i = 0; i <sz; ++i) {
            for(int j = i+1; j < sz; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        int half = sz/2;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < half; ++j) {
                std::swap(matrix[i][j], matrix[i][sz-j-1]);
            }
        }
    }
};
