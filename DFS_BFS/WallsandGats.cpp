/*
 * You are given a m x n 2D grid initialized with these three possible values.
 *
 * -1 - A wall or an obstacle.
 *  0 - A gate.
 *  INF - Infinity means an empty room.
 *  We use the value 231 - 1 = 2147483647 to represent INF as you may assume
 * that the distance to a gate is less than 2147483647. Fill each empty room
 * with the distance to its nearest gate. If it is impossible to reach a gate,
 * it should be filled with INF.
 *
 * Date: 07/21/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  using ii = pair<int, int>;

 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    queue<ii> q;
    for (int i = 0; i < rooms.size(); ++i)
      for (int j = 0; j < rooms[0].size(); ++j)
        if (rooms[i][j] == 0) q.push({i, j});

    while (!q.empty()) {
      ii curr = q.front();
      q.pop();
      int dist = rooms[curr.first][curr.second];

      // up
      if (curr.first > 0 && rooms[curr.first - 1][curr.second] == INT_MAX) {
        q.push({curr.first - 1, curr.second});
        rooms[curr.first - 1][curr.second] = dist + 1;
      }
      // down
      if (curr.first < rooms.size() - 1 &&
          rooms[curr.first + 1][curr.second] == INT_MAX) {
        q.push({curr.first + 1, curr.second});
        rooms[curr.first + 1][curr.second] = dist + 1;
      }

      // left
      if (curr.second > 0 && rooms[curr.first][curr.second - 1] == INT_MAX) {
        q.push({curr.first, curr.second - 1});
        rooms[curr.first][curr.second - 1] = dist + 1;
      }
      // right
      if (curr.second < rooms[0].size() - 1 &&
          rooms[curr.first][curr.second + 1] == INT_MAX) {
        q.push({curr.first, curr.second + 1});
        rooms[curr.first][curr.second + 1] = dist + 1;
      }
    }
  }
};
