/*
 * Given a binary search tree, write a function kthSmallest to find
 * the kth smallest element in it.
 *
 * Note: You may assume k is always valid, 1 <= k <= BST's total elements.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        // inorder traversal
        std::stack<TreeNode *> stk{};
        stk.push(root);
        while (stk.top()->left)
            stk.push(stk.top()->left);

        while (!stk.empty()) {
            auto tmp = stk.top();
            if (k == 1) return tmp->val;
            stk.pop();
            --k;
            if (tmp->right) {
                stk.push(tmp->right);
                tmp = stk.top();
                while (tmp->left) {
                    stk.push(tmp->left);
                    tmp = stk.top();
                }
            }
        }
        return -1;
    }
};
