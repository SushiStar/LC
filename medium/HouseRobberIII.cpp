/*
 * The thief has found himself a new place for his thievery again. There
 * is only one entrance to this area, called the "root." Besides the root,
 * each house has one and only one parent house. After a tour, the smart
 * thief realized that "all houses in this place forms a binary tree". It
 * will automatically contact the police if two directly-linked houses were
 * broken into on the same night.  Determine the maximum amount of money the
 * thief can rob tonight without alerting the police.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include<array>
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        auto res = robN(root);
        return std::max(res[0], res[1]);
    }

private:
    std::array<int,2> robN(TreeNode* root) {
        // Considering children and grand children
        std::array<int,2> res = {0,0};
        if (!root) return res;
        auto left = robN(root->left);
        auto right = robN(root->right);
        res[0] = std::max(left[0], left[1])+ std::max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
};
