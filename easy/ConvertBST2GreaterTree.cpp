/*
 * Given a binary search tree (BST), convert it to a greater tree such that
 * every key of the original BST is changed to the original key plus sum of
 * all keys greater than the original key in the BST;
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */

class Solution {
    privat : int sum;

public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        sum = 0;
        rightFst(root);
        return root;
    }

    void rightFst(TreeNode* root) {
        if (!root) return;
        rightFst(root->right);
        sum += root->val;
        root->val = sum;
        rightFst(root->left);
    }
};
