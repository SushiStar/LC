/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along
 * the longest path from the root node down to
 * the farthest leaf node.
 *
 * Author: Wei Du
 * Date: Mar/25/2019
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return traverse(root);
    }
    int traverse(TreeNode* root) {
        int left_depth(0), right_depth(0);
        if (root->left) left_depth = traverse(root->left);
        if (root->right) right_depth = traverse(root->right);
        return max(left_depth, right_depth)+1;
    }
}
