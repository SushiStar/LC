/*
 * Given an m x n matrix of non-negative integers representing the height
 * of each unit cell in a continent, the "Pacific Ocean" touches the left
 * and top edges of the matrix and the "Atlantic Ocean" touches the right
 * and bottom edges.
 * Water can only flow in four directions (up, down, left, or right) from
 * a cell to another one with height equal or lower.
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 *
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 *
 * Date: 05/29/2020
 * Author: Wei Du
 */

#include <array>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty()) return vector<vector<int>>();

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> atlantic(n, vector<bool>(m, false));
    vector<vector<bool>> pacific(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
      if (!pacific[i][0]) flowPacific(i, 0, matrix, pacific);
      if (!atlantic[i][m - 1]) flowAtlantic(i, m - 1, matrix, atlantic);
    }

    for (int i = 0; i < m; ++i) {
      if (!pacific[0][i]) flowPacific(0, i, matrix, pacific);
      if (!atlantic[n - 1][i]) flowAtlantic(n - 1, i, matrix, atlantic);
    }

    vector<vector<int>> result;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (atlantic[i][j] && pacific[i][j])
          result.push_back(vector<int>{i, j});

    return result;
  }

 private:
  void flowPacific(int i, int j, const vector<vector<int>>& matrix,
                   vector<vector<bool>>& pacific) {
    int n = matrix.size();
    int m = matrix[0].size();
    pacific[i][j] = true;

    if (i - 1 >= 0 && !pacific[i - 1][j] && matrix[i - 1][j] >= matrix[i][j])
      flowPacific(i - 1, j, matrix, pacific);

    if (i + 1 < n && !pacific[i + 1][j] && matrix[i + 1][j] >= matrix[i][j])
      flowPacific(i + 1, j, matrix, pacific);

    if (j - 1 >= 0 && !pacific[i][j - 1] && matrix[i][j - 1] >= matrix[i][j])
      flowPacific(i, j - 1, matrix, pacific);

    if (j + 1 < m && !pacific[i][j + 1] && matrix[i][j + 1] >= matrix[i][j])
      flowPacific(i, j + 1, matrix, pacific);
  }

  void flowAtlantic(int i, int j, const vector<vector<int>>& matrix,
                    vector<vector<bool>>& atlantic) {
    int n = matrix.size();
    int m = matrix[0].size();
    atlantic[i][j] = true;

    if (i - 1 >= 0 && !atlantic[i - 1][j] && matrix[i - 1][j] >= matrix[i][j])
      flowAtlantic(i - 1, j, matrix, atlantic);

    if (i + 1 < n && !atlantic[i + 1][j] && matrix[i + 1][j] >= matrix[i][j])
      flowAtlantic(i + 1, j, matrix, atlantic);

    if (j - 1 >= 0 && !atlantic[i][j - 1] && matrix[i][j - 1] >= matrix[i][j])
      flowAtlantic(i, j - 1, matrix, atlantic);

    if (j + 1 < m && !atlantic[i][j + 1] && matrix[i][j + 1] >= matrix[i][j])
      flowAtlantic(i, j + 1, matrix, atlantic);
  }
};
