/*
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * Date: 04/08/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty() || triangle[0].empty()) return 0;
    if (triangle.size() == 1) return triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i) {
      int currLen(triangle[i].size());
      triangle[i][0] += triangle[i - 1][0];
      triangle[i][currLen - 1] += triangle[i - 1][currLen - 2];
      for (int j = 1; j < currLen - 1; ++j)
        triangle[i][j] += std::min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    }
    int result{INT_MAX};
    for (auto &num : triangle.back()) result = std::min(result, num);
    return result;
  }
  int minimumTotal1(vector<vector<int>> &triangle) {
    vector<int> res(triangle.size() + 1);
    for (int i = triangle.size() - 1; i >= 0; --i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        res[j] = min(res[j], res[j + 1]) + triangle[i][j];
      }
    }
    return res[0];
  }
};
