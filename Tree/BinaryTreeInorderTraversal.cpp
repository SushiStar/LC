/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * Date: 03/14/2020
 * Author: Wei Du
 */
 
class Solution {
public:
    vector<int> inorderTaversal(TreeNode* root) {
        std::vector<int> res;
        subTraverse(root, res);
        return res;
    }

    void subTraverse(TreeNode* node, vector<int>& res) {
        if(!node) return;
        subTraverse(node->left, res);
        res.push_back(node->val);
        subTraverse(node->right, res);
        return;
    }
};
