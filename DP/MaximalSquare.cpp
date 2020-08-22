/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return it's area.
 *
 * Date: 06/04/2020
 * Author: Wei Du
 */
#include "../common.h"
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int ret(0);

    // the largest side length of the square ended with down-right corner at i,j
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    vector<int> height(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
      int width = 0;
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == '0') {
          height[j] = 0;
          width = 0;
          continue;
        }
        ++height[j];
        ++width;
        dp[i][j] = std::min(width, height[j]);
        if (i > 0 && j > 0) {
          dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i][j]);
        }
        ret = std::max(dp[i][j], ret);
      }
    }
    return ret * ret;
  }
};

class Solution1 {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int ret{0};
    int numRow(matrix.size());
    int numCol(matrix[0].size());
    std::vector<int> height(numCol, 0);
    std::vector<int> leftBoundary(numCol, 0);
    std::vector<int> rightBoundary(numCol, numCol - 1);
    for (int i = 0; i < numRow; ++i) {
      int currLeftBoundary(0);
      int currRightBoundary(numCol - 1);
      for (int j = numCol - 1; j > -1; --j) {
        if (matrix[i][j] == '1') {
          ++height[j];
          rightBoundary[j] = std::min(rightBoundary[j], currRightBoundary);
        } else {
          height[j] = 0;
          currRightBoundary = j - 1;
          rightBoundary[j] = numCol - 1;
        }
      }

      for (int j = 0; j < numCol; ++j) {
        if (matrix[i][j] == '1') {
          leftBoundary[j] = std::max(leftBoundary[j], currLeftBoundary);
        } else {
          leftBoundary[j] = 0;
          currLeftBoundary = j + 1;
          continue;
        }
        ret = std::max(
            ret, std::min((rightBoundary[j] - leftBoundary[j] + 1), height[j]));
      }
    }
    return ret * ret;
  }
};
