/*
 * Given a binary tree, return the vertical order traversal of
 * its nodes values. For each node at position (X, Y), its left
 * and right children respectively will be at positions (x-1, y-1)
 * and (x+1, y-1). Running a vertical line from X = -infinity to
 * X = +infinity, whenever the vertical line touches some nodes,
 * we report the values of the nodes in order from top to bottom
 * (Decreasing Y coordinates).
 * If two nodes have the same position, then the value of the node
 * that is reported first is the value that is smaller.
 *
 * Return an list of non-empty reports in order of X coordinates.
 * Every report will have a list of values of nodes.
 *
 * Date: 05/23/2020
 * Author: Wei Du
 */
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    std::vector<std::vector<int>> ret{};
    if (!root) return ret;
    // row, col, bin
    std::unordered_map<int, std::unordered_map<int, std::vector<int>>> map2d;
    std::unordered_map<TreeNode *, int> colIdx;
    std::unordered_map<TreeNode *, int> rowIdx;
    colIdx[root] = 0;
    rowIdx[root] = 0;
    int minColIdx{0};
    int maxColIdx{0};

    std::vector<TreeNode *> bfsCurr{root};
    std::vector<TreeNode *> bfsNext{};
    while (!bfsCurr.empty()) {
      for (TreeNode *parent : bfsCurr) {
        minColIdx = std::min(minColIdx, colIdx[parent]);
        maxColIdx = std::max(maxColIdx, colIdx[parent]);
        map2d[rowIdx[parent]][colIdx[parent]].push_back(parent->val);
        if (parent->left) {
          bfsNext.push_back(parent->left);
          rowIdx[parent->left] = rowIdx[parent] + 1;
          colIdx[parent->left] = colIdx[parent] - 1;
        }
        if (parent->right) {
          bfsNext.push_back(parent->right);
          rowIdx[parent->right] = rowIdx[parent] + 1;
          colIdx[parent->right] = colIdx[parent] + 1;
        }
      }
      bfsCurr.clear();
      std::swap(bfsCurr, bfsNext);
    }
    ret.resize(maxColIdx - minColIdx + 1);
    for (int i = minColIdx; i <= maxColIdx; ++i) {
      int j = 0;
      while (!map2d[j].empty()) {
        std::sort(map2d[j][i].begin(), map2d[j][i].end());
        ret[i - minColIdx].insert(ret[i - minColIdx].end(), map2d[j][i].begin(),
                                  map2d[j][i].end());
        ++j;
      }
    }
    return ret;
  }
};
