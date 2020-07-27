/*
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 *
 * Date: 07/26/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
      std::queue<TreeNode*> q;
      int levelcount{1};
      int lastlevelcount{1};
      double sum{0};
      vector<double> ret;

      q.push(root);
      while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        sum += cur->val;
        --levelcount;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);

        if (levelcount == 0) {
          ret.push_back(sum/lastlevelcount);
          levelcount = q.size();
          lastlevelcount = levelcount;
          sum = 0;
        }
      }
      return ret;
    }
};
