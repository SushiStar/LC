/*
 * Given a binary tree, find the lowest common ancestor (LCA)
 * of two given nodes in the tree.
 *
 * Date: 05/02/2020
 * Author: Wei Du
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return nullptr;
        else if (root == p) return p;
        else if (root == q) return q;

        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right,p, q);
        if ((l == p && r == q) ||(l == q && r == p)) return root;
        else if (!l && !r) return nullptr;
        return l ? l : r;
    }
};
