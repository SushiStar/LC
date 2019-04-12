/*
 * Given a binary tree, find the lowest common ancestor (LCA)
 * of two given nodes in the tree.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 *
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        auto l = lowestCommonAncestor(root->left, p,q);
        auto r = lowestCommonAncestor(root->right, p,q);
        if (l) return l;
        if (r) return r;
        if (containX(root, p) && containX(root, q)) return root;
    }
    bool containX(TreeNode* root, TreeNode* X) {
        if (!root) return false;
        if (root == X) return true;
        if (containX(root->left, X)) return true;
        return(containX(root->right, X));
    }
};
