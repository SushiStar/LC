/*
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;
        bool tmp;
        return countUnivalSubtrees(root, tmp);
    }

private:
    int countUnivalSubtrees(TreeNode *root, bool &validSubtree) {
        if (!root->left && !root->right) {
            validSubtree = true;
            return 1;
        }
        int ret{0};
        validSubtree = false;
        bool validLeft(true), validRight(true);
        if (root->left) ret += countUnivalSubtrees(root->left, validLeft);
        if (root->right) ret += countUnivalSubtrees(root->right, validRight);
        if (validLeft && validRight &&
            (!root->right || root->val == root->right->val) &&
            (!root->left || root->val == root->left->val)) {
            validSubtree = true;
            ++ret;
        }
        return ret;
    }
};
