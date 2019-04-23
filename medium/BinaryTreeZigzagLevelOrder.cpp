/*
 * Given a binary tree, return the zigzag level order traversal
 * of its nodes' values. (ie, from left to right, then right to
 * left for the next level and alternate between).
 *
 * Date: Apr/23/2019
 * Author: Wei Du
 */

#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        bool left = false;
        std::vector<TreeNode*> one{root};
        std::vector<TreeNode*> two;
        std::vector<int> value{root->val};
        res.push_back(value);
        while (!one.empty()) {
            two.clear();
            value.clear();
            for (int i = 0; i < one.size(); ++i) {
                if (one[i]->left) {
                    two.push_back(one[i]->left);
                    value.push_back(one[i]->left->val);
                } 
                if (one[i]->right) {
                    two.push_back(one[i]->right);
                    value.push_back(one[i]->right->val);
                }
            }
            one.clear();
            one = std::move(two);
            if (!left) {
                std::reverse(value.begin(), value.end());
            }
            res.push_back(value);
            left = !left;
        }
        if (res.back().empty()) res.pop_back();
        return res;
    }
};
