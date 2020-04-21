/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf
 * path such that adding up all the values along the path equals the given
 * sum.
 *
 * Date: 04/21/2020
 * Author: Wei Du
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!(root->left || root->right)) return root->val == sum;
        int res(sum - root->val);
        return (hasPathSum(root->left, res) || hasPathSum(root->right, res));
    }
};
