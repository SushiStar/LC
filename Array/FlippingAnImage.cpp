/*
 * Given an binary matrix A, we want to flip the image horizontally, then
 * invert it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1,1,0] horizontally results int [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced
 * by 0. For example, inverting [0,1,1] results in [1,0,0].
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        if (A[0].size() != 1) {
            for (auto &row : A)
                std::reverse(row.begin(), row.end());
        }
        for (auto &row : A) {
            for (int i = 0; i < row.size(); ++i)
                row[i] = 1 - row[i];
        }
        return A;
    }
};
