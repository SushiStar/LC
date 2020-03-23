/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from
 * the root down to the farthest leaf node.
 *
 * Date: 03/23/2020
 * Author: Wei Du
 *
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root) {
            return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;  
        } 
        return 0;
    }
};
