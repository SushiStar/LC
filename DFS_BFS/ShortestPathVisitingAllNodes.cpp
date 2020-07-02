/*
 * An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is
 * given as graph. graph.length = N, and j != i is in the list graph[i] exactly
 * once, if and only if nodes i and j are connected. Return the length of the
 * shortest path that visits every node. You may start and stop at any node, you
 * may revisit nodes multiple times, and you may reuse edges.
 *
 * 1 <= graph.length <= 12
 * 0 <= graph[i].length < graph.length
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  using ii = pair<int, int>;

 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    queue<ii> q;
    unordered_set<string> visited;
    int target{0};
    for (int i = 0; i < graph.size(); ++i) {
      int status = (1 << (i + 1));
      target = target | status;
      visited.insert(std::to_string(status) + ":" + std::to_string(i));
      q.push({status, i});
    }
    int currCnt = q.size(), nxtCnt{0}, layer{0};
    while (!q.empty()) {
      ii curr = q.front();
      q.pop();
      currCnt--;
      if (curr.first == target) return layer;
      for (int nb : graph[curr.second]) {
        int nxtStatus = curr.first | (1 << (nb + 1));
        string key(std::to_string(nxtStatus) + ":" + to_string(nb));
        if (visited.count(key)) continue;
        visited.insert(key);
        q.push({nxtStatus, nb});
        nxtCnt++;
      }
      if (!currCnt) {
        currCnt = nxtCnt;
        nxtCnt = 0;
        ++layer;
      }
    }
    return -1;
  }
};
