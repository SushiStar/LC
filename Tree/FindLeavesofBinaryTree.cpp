/*
 * Given a binary tree, collect a tree's nodes as if you were doing this:
 * Collect and remove all leaves, repeat until the tree is empty.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  int dfs(TreeNode* root, vector<vector<int>>& ret) {
    if (!root) return -1;
    int curLevel = std::max(dfs(root->left, ret), dfs(root->right, ret))+1;
    if (curLevel == ret.size()) ret.push_back({});
    ret[curLevel].push_back(root->val);
    return curLevel;
  }

 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ret;
    dfs(root, ret);
    return ret;
  }
};
