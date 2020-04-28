/*
 * You are given an nxn 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify
 * the input 2D matrix directly. DO NOT allocate another 2D matrix and
 * do the rotation.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
	if (matrix.empty()) return;
	for (int i = 0; i < matrix.size(); ++i)
	    for (int j = i + 1; j < matrix.size(); ++j)
		std::swap(matrix[i][j], matrix[j][i]);
	for (int i = 0; i < matrix.size(); ++i)
	    std::reverse(matrix[i].begin(), matrix[i].end());
    }
};
