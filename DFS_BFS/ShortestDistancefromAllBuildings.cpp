/*
 * You want to build a house on an empty land which reaches all buildings in the
 * shortest amount of distance. You can only move up, down, left and right. You
 * are given a 2D grid of values 0, 1 or 2, where:
 *
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through
 *
 * Date: 08/03/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  using ii = pair<int, int>;
  vector<vector<int>> distance;
  vector<vector<bool>> visited;
  vector<vector<int>> reachby;
  int numBuilding;
  int row, col;

  void bfs(const vector<vector<int>> &grid, int x, int y) {
    for (int i = 0; i < row; ++i)
      std::fill(visited[i].begin(), visited[i].end(), false);

    std::queue<ii> q;
    q.push({x, y});
    int dist{1}, cnt{0};

    cnt = q.size();
    while (!q.empty()) {
      ii cur = q.front();
      q.pop();
      --cnt;

      if (cur.first > 0 && grid[cur.first - 1][cur.second] == 0 &&
          !visited[cur.first - 1][cur.second]) {
        distance[cur.first - 1][cur.second] += dist;
        visited[cur.first - 1][cur.second] = true;
        ++reachby[cur.first - 1][cur.second];
        q.push({cur.first - 1, cur.second});
      }
      if (cur.first + 1 < row && grid[cur.first + 1][cur.second] == 0 &&
          !visited[cur.first + 1][cur.second]) {
        distance[cur.first + 1][cur.second] += dist;
        visited[cur.first + 1][cur.second] = true;
        ++reachby[cur.first + 1][cur.second];
        q.push({cur.first + 1, cur.second});
      }
      if (cur.second > 0 && grid[cur.first][cur.second - 1] == 0 &&
          !visited[cur.first][cur.second - 1]) {
        distance[cur.first][cur.second - 1] += dist;
        visited[cur.first][cur.second - 1] = true;
        ++reachby[cur.first][cur.second - 1];
        q.push({cur.first, cur.second - 1});
      }
      if (cur.second + 1 < col && grid[cur.first][cur.second + 1] == 0 &&
          !visited[cur.first][cur.second + 1]) {
        distance[cur.first][cur.second + 1] += dist;
        visited[cur.first][cur.second + 1] = true;
        ++reachby[cur.first][cur.second + 1];
        q.push({cur.first, cur.second + 1});
      }
      if (cnt == 0) {
        cnt = q.size();
        ++dist;
      }
    }
  }

 public:
  int shortestDistance(vector<vector<int>> &grid) {
    row = grid.size();
    col = grid[0].size();
    distance.resize(row, vector<int>(col, 0));
    visited.resize(row, vector<bool>(col, false));
    reachby.resize(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1) {
          bfs(grid, i, j);
          ++numBuilding;
        }
      }
    }

    int ret{INT_MAX};
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (grid[i][j] == 0 && reachby[i][j] == numBuilding)
          ret = ret > distance[i][j] ? distance[i][j] : ret;
    return ret == INT_MAX ? -1 : ret;
  }
};
