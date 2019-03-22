/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * Date: Mar/22/2019
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
        if(node->left) {
            subTraverse(node->left, res);
        }
        res.push_back(node->val);
        if(node->right) {
            subTraverse(node->right, res);
        }
        return;
    }
};
