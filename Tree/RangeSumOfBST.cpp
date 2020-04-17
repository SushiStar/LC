/*
 * Given the root node of a binary search tree, return the sum of values
 * of all nodes with value between L and R (inclusive).
 *
 * The binary search tree is gauarnateed to have unique values.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
class Solution {
public:
    int rangeSumBST(TreeNode *root, int L, int R) {
        if (!root) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        if (root->val > R) return rangeSumBST(root->left, L, R);
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) +
               root->val;
    }
};
