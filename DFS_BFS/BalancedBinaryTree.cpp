/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 *  A binary tree in which the left and right subtrees of every
 *  node differ in height by no more than 1.
 *
 *  Date: 04/01/2020
 *  Author: Wei Du
 */

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int depth{0};
        return depthAndBalance(root, depth);
    }

private:
    bool depthAndBalance(TreeNode *root, int &depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int ldepth{0}, rdepth{0};
        if (depthAndBalance(root->left, ldepth) &&
            depthAndBalance(root->right, rdepth)) {
            if (std::abs(ldepth - rdepth) > 1) return false;
            depth = std::max(ldepth, rdepth) + 1;
            return true;
        }
        return false;
    }
};
