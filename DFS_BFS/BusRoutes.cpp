/*
 * We have a list of bus routes. Each routes[i] is a bus route that the i-th bus
 * repeats forever. For example if routes[0] = [1, 5, 7], this means that the
 * first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->...
 * forever.
 *
 * We start at bus stop S (initially not on a bus), and we want to go to bus
 * stop T. Travelling by buses only, what is the least number of buses we must
 * take to reach our destination? Return -1 if it is not possible.
 *
 * Date: 08/03/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  bool connectedRoute[501][501];

 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;
    for (int i = 0; i < 501; ++i)
      std::fill(connectedRoute[i], connectedRoute[i] + 501, false);

    unordered_map<int, vector<int>> stopOnRoute;
    queue<int> q;
    unordered_set<int> taken;
    unordered_set<int> targetRoute;
    for (int i = 0; i < routes.size(); ++i) {
      for (int stop : routes[i]) {
        stopOnRoute[stop].push_back(i);
        if (stop == S) {
          q.push(i);
          taken.insert(i);
        } else if (stop == T)
          targetRoute.insert(i);
      }
    }

    for (auto pr : stopOnRoute) {
      vector<int> intersection(pr.second.begin(), pr.second.end());
      for (int i = 0; i < intersection.size(); ++i) {
        for (int j = i + 1; j < intersection.size(); ++j) {
          connectedRoute[intersection[i]][intersection[j]] = true;
          connectedRoute[intersection[j]][intersection[i]] = true;
        }
      }
    }

    int cnt{(int)q.size()};
    int ret{1};
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      --cnt;
      if (targetRoute.count(cur)) return ret;

      for (int i = 0; i < 501; ++i) {
        if (connectedRoute[cur][i] && !taken.count(i)) {
          q.push(i);
          taken.insert(i);
        }
      }

      if (cnt == 0) {
        cnt = q.size();
        ++ret;
      }
    }
    return -1;
  }
};
