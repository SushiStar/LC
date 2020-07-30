/*
 * We have a two dimensional matrix A where each value is 0 or 1.
 *
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 *
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 *
 * Return the highest possible score.
 */
#include "../common.h"

class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int row(A.size()), col(A[0].size());
    // consider rows, the first item should be 1;
    for (int i = 0; i < row; ++i) {
      if (A[i][0] == 1) continue;
      for (int j = 0; j < col; ++j) A[i][j] = 1 - A[i][j];
    }

    int res(0), base(pow(2, col- 1) + 0.5);
    res+=row*base;
    // consider columns
    for (int j = 1; j < col; ++j)  {
      base/=2;
      int sum{0};
      for (int i = 0; i < row; ++i)
        sum+=A[i][j];
      res += std::max(sum, row-sum)*base;
    }
    return res;
  }
};
