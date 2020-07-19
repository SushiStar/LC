/*
 * For an undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 *
 * Format:
 * The graph contains n nodes which are labeled from 0 to n-1. You will be given
 * the number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0,1] is the same as [1,0] and thus will not appear together
 * in edges.
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */
#include "../common.h"
// it is assumed no circle exist
// BFS is too slow

// remove leaves layer by layer, the rest 1 or two nodes could be the answer
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1) return std::vector<int>{0};
    if (n == 2) return std::vector<int>{0, 1};
    std::unordered_map<int, std::unordered_set<int>> neighbors;
    std::unordered_set<int> remover;
    for (auto &e : edges) {
      remover.insert(e[0]);
      remover.insert(e[1]);
      neighbors[e[0]].insert(e[1]);
      neighbors[e[1]].insert(e[0]);
    }
    while (remover.size() > 2) {
      std::vector<int> buffer;
      for (auto curr : remover) {
        if (neighbors[curr].size() == 1) buffer.push_back(curr);
      }
      for (int leaf : buffer) {
        if (!neighbors[leaf].empty()) {
          int n = *(neighbors[leaf].begin());
          neighbors[n].erase(leaf);
          neighbors[leaf].clear();
        }
        remover.erase(leaf);
      }
    }
    std::vector<int> rlt(remover.begin(), remover.end());
    return rlt;
  }
};
