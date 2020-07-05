/*
 * There are n houses in a village. We want to supply water for all the houses
 * by building wells and laying pipes. For each house i, we can either build a
 * well inside it directly with cost wells[i], or pipe in water from another
 * well to it. The costs to lay pipes between houses are given by the array
 * pipes, where each pipes[i] = [house1, house2, cost] represents the cost to
 * connect house1 and house2 together using a pipe. Connections are
 * bidirectional. Find the minimum total cost to supply water to all houses.
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <functional>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

// Minimum Spanning Tree
// Prim's algorithm
// TLE bcs each process takes O(n) under this problem
class Solution {
  using vi = vector<int>;
  using vvi = vector<vector<int>>;
  using ii = pair<int, int>;

  vi visited;
  vvi costs;
  priority_queue<ii, vector<ii>, function<bool(const ii &a, const ii &b)>> *pq;
  void process(int vtx) {
    visited[vtx] = 1;
    for (int i = 0; i < (int)costs.size(); ++i) {
      if (costs[vtx][i] > 0 && !visited[i]) {
        pq->push({costs[vtx][i], i});
      }
    }
  }

 public:
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    auto cmp{[](const ii &a, const ii &b) { return a.first > b.first; }};
    pq = new priority_queue<ii, vector<ii>,
                            function<bool(const ii &a, const ii &b)>>(cmp);
    visited.resize(n + 1, 0);
    costs.resize(n + 1, vi(n + 1, -1));
    for (vector<int> &unit : pipes)
      costs[unit[0]][unit[1]] = costs[unit[1]][unit[0]] = unit[2];
    for (int i = 1; i <= n; ++i) costs[0][i] = costs[i][0] = wells[i - 1];

    // MST from node 0;
    int ret{0};
    process(0);
    while (!pq->empty()) {
      ii tmp = pq->top();
      pq->pop();
      if (!visited[tmp.second]) {
        ret += tmp.first;
        process(tmp.second);
      }
    }
    return ret;
  }
};

// Kruskal's algorithm
class Solution1 {
  using ii = pair<int, int>;

 public:
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    parent.resize(n + 1);
    std::iota(parent.begin(), parent.end(), 0);
    vector<pair<int, ii>> EdgeList;  // weight, two vertices

    for (auto &e : pipes) EdgeList.push_back({e[2], {e[0], e[1]}});
    for (int i = 1; i <= n; ++i) EdgeList.push_back({wells[i - 1], {0, i}});
    std::sort(EdgeList.begin(), EdgeList.end());

    int ret{0};
    numSets = n + 1;  // from 0 to n
    for (auto &e : EdgeList) {
      if (numSets == 1) break;
      int v1{e.second.first}, v2{e.second.second};
      if (uni(v1, v2)) ret += e.first;
    }
    return ret;
  }

 private:
  vector<int> parent;
  int numSets;

  int findParent(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
  }

  bool uni(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    if (px != py) {
      parent[py] = px;
      --numSets;
      return true;
    }
    return false;
  }
};
