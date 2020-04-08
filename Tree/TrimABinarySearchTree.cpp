/*
 * Given a binary search tree and the lowest and highest boundaries as L and R,
 * trim the tree so that all its elements lies in [L,R] (R>=L). You might need
 * to change the root of the tree, so the result return the new root of the
 * trimmed binary search tree.
 *
 * Date: 04/07/2020
 * Author: Wei Du
 */
class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        while (root) {
            if (root->val < L)
                root = root->right;
            else if (root->val > R)
                root = root->left;
            else
                break;
        }
        if (!root) return root;

        std::stack<TreeNode *> stk;
        TreeNode *tmp(root);
        while (tmp) {
            if (tmp->left) {
                if (tmp->left->val >= L)
                    tmp = tmp->left;
                else
                    tmp->left = tmp->left->right;
            } else {
                tmp = nullptr;
            }
        }
        tmp = root;
        while (tmp) {
            if (tmp->right) {
                if (tmp->right->val <= R)
                    tmp = tmp->right;
                else
                    tmp->right = tmp->right->left;
            } else {
                tmp = nullptr;
            }
        }
        return root;
    }
};

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) return root;
        if (root->val < L) {
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            return trimBST(root->left, L, R);
        } else {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }
        return root;
    }
};
