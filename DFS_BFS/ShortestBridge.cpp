/*
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.) Now, we
 * may change 0s to 1s so as to connect the two islands together to form 1
 * island. Return the smallest number of 0s that must be flipped.  (It is
 * guaranteed that the answer is at least 1.)
 *
 * Date: 08/13/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  using ii = std::pair<int, int>;

public:
  int shortestBridge(vector<vector<int>> &A) {
    int row{(int)A.size()}, col((int)A[0].size());
    ii origin{-1, -1};
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (A[i][j] == 1) {
          origin = {i, j};
          break;
        }
      }
      if (origin.first > -1) break;
    }
    std::vector<ii> border;
    queue<ii> q;
    q.push(origin);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      int cnt{0};
      if (cur.first > 0 && A[cur.first - 1][cur.second] > 0) {
        ++cnt;
        if (A[cur.first - 1][cur.second] == 1)
          q.push({cur.first - 1, cur.second});
      }
      if (cur.first < row - 1 && A[cur.first + 1][cur.second] > 0) {
        ++cnt;
        if (A[cur.first + 1][cur.second] == 1)
          q.push({cur.first + 1, cur.second});
      }
      if (cur.second > 0 && A[cur.first][cur.second - 1] > 0) {
        ++cnt;
        if (A[cur.first][cur.second - 1] == 1)
          q.push({cur.first, cur.second - 1});
      }
      if (cur.second < col - 1 && A[cur.first][cur.second + 1] > 0) {
        ++cnt;
        if (A[cur.first][cur.second + 1] == 1)
          q.push({cur.first, cur.second + 1});
      }
      A[cur.first][cur.second] = 2;
      if (cnt < 4) border.push_back(cur);
    }
    int ret{INT_MAX};
    std::vector<vector<bool>> visited(row, std::vector<bool>(col, false));
    for (auto &coord : border) {
      queue<ii> bfs;
      bfs.push(coord);
      int cnt{1};
      int steps{0};
      while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        if (A[cur.first][cur.second] == 1) break;
        --cnt;

        if (cur.first > 0 && !visited[cur.first - 1][cur.second] &&
            A[cur.first - 1][cur.second] == 0) {
          visited[cur.first - 1][cur.second] = true;
          bfs.push({cur.first - 1, cur.second});
        }
        if (cur.first < row - 1 && !visited[cur.first + 1][cur.second] &&
            A[cur.first + 1][cur.second] == 0) {
          visited[cur.first + 1][cur.second] = true;
          bfs.push({cur.first + 1, cur.second});
        }
        if (cur.second > 0 && !visited[cur.first][cur.second - 1] &&
            A[cur.first][cur.second - 1] == 0) {
          visited[cur.first][cur.second - 1] = true;
          bfs.push({cur.first, cur.second - 1});
        }
        if (cur.second < col - 1 && !visited[cur.first][cur.second + 1] &&
            A[cur.first][cur.second + 1] == 0) {
          visited[cur.first][cur.second + 1] = true;
          bfs.push({cur.first, cur.second + 1});
        }

        if (cnt == 0) {
          cnt = bfs.size();
          ++steps;
        }
      }
      ret = std::min(ret, steps);
      for (auto &vct : visited) std::fill(vct.begin(), vct.end(), false);
    }
    return ret - 1;
  }
};
