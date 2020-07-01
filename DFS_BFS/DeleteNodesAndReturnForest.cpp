/*
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a
 * forest(a disjoint union of trees). Return the roots of the trees in the
 * remaining forest. You may return the result in any order.
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

// Definition for a binary tree node.
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
  bool del[1001];
 public:
   vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
     if (!root) return {};
     for (int i : to_delete) del[i] = true;
     vector<TreeNode*> ret{};
     vector<TreeNode*> bfs{root};
     int idx{0};
     while (idx < bfs.size()) {
       auto tmp = bfs[idx];
       if (del[tmp->val] && tmp->left && !del[tmp->left->val])
         ret.push_back(tmp->left);
       if (del[tmp->val] && tmp->right && !del[tmp->right->val])
         ret.push_back(tmp->right);

       ++idx;
       if (tmp->left) {
         bfs.push_back(tmp->left);
         if (del[tmp->left->val])
           tmp->left = nullptr;
       }
       if (tmp->right) {
         bfs.push_back(tmp->right);
         if (del[tmp->right->val])
           tmp->right = nullptr;
       }
     }
     ret.push_back(root);
     if (del[root->val]) {
       ret.pop_back();
       root->left = nullptr;
       root->right = nullptr;
     }
     return ret;
   }
};
