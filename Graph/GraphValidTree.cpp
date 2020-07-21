/*
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge
 * is a pair of nodes), write a function to check whether these edges make up a
 * valid tree.
 *
 * Date: 07/20/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    // a tree needs exactly n-1 edgegs
    if (edges.size() != n - 1) return false;

    // if there are n-1 edges, should be all connected
    parent.resize(n);
    numsets = n;
    std::iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < edges.size(); ++i) uni(edges[i][0], edges[i][1]);
    return numsets == 1;
  }

 private:
  vector<int> parent;
  int numsets;
  void uni(int x, int y) {
    int px{findparent(x)};
    int py{findparent(y)};
    if (px != py) {
      parent[py] = px;
      --numsets;
    }
  }

  int findparent(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
  }
};
