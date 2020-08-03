/*
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to find the number of connected
 * components in an undirected graph.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  static const int parentsize{100001};
  int parent[parentsize];
  int find(int x){
    while (parent[x]!=x) x = parent[x];
    return x;
  }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
      std::iota(parent, parent+parentsize, 0);
      for (auto &vct: edges) {
        int parent0 = find(vct[0]);
        int parent1 = find(vct[1]);
        if (parent0 != parent1) {
          parent[parent1] = parent0;
          --n;
        }
      }
      return n;
    }
};
