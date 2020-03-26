/*
 * Definition of a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/25/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> result; 
        if (!root) return result;
        std::vector<TreeNode*> buffer[2];
        int idx0{0};
        int idx1{1};
        buffer[idx0].push_back(root);
        while (!buffer[idx0].empty()) {
            std::vector<int> level{};
            for (auto node : buffer[idx0]) {
                level.push_back(node->val);
                if (node->left) buffer[idx1].push_back(node->left);
                if (node->right) buffer[idx1].push_back(node->right);
            }
            result.push_back(level);
            buffer[idx0].clear();
            std::swap(idx0, idx1);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
