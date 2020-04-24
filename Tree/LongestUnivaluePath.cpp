/*
 * Given a binary tree, find the length of the longest path where each
 * node in the path has the same value.
 * This path may or may not pass through the root.
 *
 * The length of path between two nodes is represented by the nubmer of edges
 * between them.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root) return 0;
        int pathLen(0);
        return longestUnivaluePath(root, pathLen);
    }

private:
    int longestUnivaluePath(TreeNode *root, int &pathLen) {
        if (!root->left && !root->right) {
            pathLen = 0;
            return 0;
        }
        int lLen(0), lpathLen(0), accL(0);
        int rLen(0), rpathLen(0), accR(0);
        if (root->left) {
            lLen = longestUnivaluePath(root->left, lpathLen);
            accL = root->val == root->left->val ? lpathLen + 1 : 0;
        }
        if (root->right) {
            rLen = longestUnivaluePath(root->right, rpathLen);
            accR = root->val == root->right->val ? rpathLen + 1 : 0;
        }
        int ret = std::max(rLen, lLen);
        pathLen = std::max(accL, accR);
        ret = std::max(ret, accL + accR);
        return ret;
    }
};
