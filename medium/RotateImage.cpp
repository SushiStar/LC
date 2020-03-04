/*
 * You are given an nxn 2D matrix representing an image,
 * Rotate the images by 90 degrees clockwise.
 *
 * You have to rotate the image in place, which means you have to
 * modify the input 2D matrix directly.
 * Do not allocate another 2D matrix and do the rotation.
 *
 * hint: Diagonal mirror, and flip
 *
 * Date: 03/04/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()||matrix[0].empty()) return;
        int sz = matrix.size()-1;
        for (int i = 0; i <sz; ++i) {
            for(int j = 0; j < sz-1; ++j) {
                std::swap(matrix[j][i], matrix[sz-i][sz-j]);
            }
        }
        int half = sz/2;
        for (int j = 0; j < half; ++j) {
            std::swap(matrix[j], matrix[sz-j]);
        }
    }
};
