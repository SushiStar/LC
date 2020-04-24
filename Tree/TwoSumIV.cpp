/*
 * Given a Binary Search Tree and a target number, return true if
 * there exist two elements in the BST such that their sum is equal
 * to the given target.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        std::unordered_set<int> sett{};
        std::vector<TreeNode *> stk{root};
        while (!stk.empty()) {
            TreeNode *tmp(stk.back());
            tmp = tmp->left;
            while (tmp) {
                stk.push_back(tmp);
                tmp = tmp->left;
            }

            while (!stk.empty()) {
                auto curr{stk.back()};
                if (sett.find(k - curr->val) != sett.end()) return true;
                sett.insert(curr->val);
                stk.pop_back();
                if (curr->right) {
                    stk.push_back(curr->right);
                    break;
                }
            }
        }
        return false;
    }
};
