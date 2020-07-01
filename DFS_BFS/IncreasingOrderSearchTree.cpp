/*
 * Given a binary search tree, rearrange the tree in-order so that the leftmost
 * node in the tree is now the root of the tree, and every node has not left
 * child and only 1 right child.
 *
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */

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
 public:
   TreeNode *increasingBST(TreeNode *root) {
     if (!root) return root;
     TreeNode* newRoot;
     if (root->left) {
       newRoot = increasingBST(root->left);
       auto tmp(newRoot);
       while (tmp->right) tmp = tmp->right;
       tmp->right = root;
       root->left = nullptr;
     } else {
       newRoot = root;
     }
     root->right = increasingBST(root->right);
     return newRoot;
   }
};
