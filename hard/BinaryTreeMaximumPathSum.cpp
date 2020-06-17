/*
 * Given a non-empty binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes
 * from starting node to any node in the tree along the parent
 * child connections. The path must contain at least one node
 * and does not need to go through the root.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Date: May/10/2019
 * Author: Wei Du
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxsm;
        return maxPath(root, maxsm);
    }

    int maxPath(TreeNode* curr, int& maxline) {
        if (!curr) {
            maxline = INT_MIN;
            return INT_MIN;
        }
        int lmaxline(INT_MIN), rmaxline(INT_MIN);
        int lmax = maxPath(curr->left, lmaxline);
        int rmax = maxPath(curr->right, rmaxline);

        // abort child line or not
        lmaxline = lmaxline < 0 ? 0 : lmaxline;
        rmaxline = rmaxline < 0 ? 0 : rmaxline;

        // max line has to via the current node at least
        maxline = curr->val + std::max(lmaxline, rmaxline);
        return std::max(curr->val + lmaxline + rmaxline, std::max(lmax, rmax));
    }
};
