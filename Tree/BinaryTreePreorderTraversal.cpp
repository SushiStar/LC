/*
 * Given a binary tree, return the reporder traversal of its
 * nodes' values.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> ret{};
        if (!root) return ret;
        std::vector<TreeNode *> stk{root};
        while (!stk.empty()) {
            auto tmp = stk.back();
            stk.pop_back();
            ret.push_back(tmp->val);
            if (tmp->right) stk.push_back(tmp->right);
            if (tmp->left) stk.push_back(tmp->left);
        }
        return ret;
    }
};
