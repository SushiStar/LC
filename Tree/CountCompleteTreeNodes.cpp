/*
 * Given a complete binary tree, count the number of nodes.
 *
 * Note: In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level are as far left
 * as possible. It can be between 1 and pow(2,h) nodes inclusive at the
 * last level h.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        if (!root->right) return root->left ? 2 : 1;
        return std::max(maxChild(root->left, 1, true),
                        maxChild(root->right, 1, false));
    }

private:
    int maxChild(TreeNode *root, int parentIdx, bool left) {
        int rootIdx = parentIdx * 2 + (left ? 0 : 1);
        if (root->left || root->right) {
            int leftMax = root->left ? maxChild(root->left, rootIdx, true) : 0;
            int rightMax =
                root->right ? maxChild(root->right, rootIdx, false) : 0;
            return std::max(leftMax, rightMax);
        }
        return rootIdx;
    }
};
