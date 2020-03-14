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

// Recursion version
class Solution {
public:
    vector<int> inorderTaversal(TreeNode *root) {
        std::vector<int> res;
        subTraverse(root, res);
        return res;
    }
private:
    void subTraverse(TreeNode *node, vector<int> &res) {
        if (!node) return;
        subTraverse(node->left, res);
        res.push_back(node->val);
        subTraverse(node->right, res);
        return;
    }
};


// loop version
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> rsl;
        std::stack<TreeNode*> stk;
        while (root!=nullptr || !stk.empty()){ 
            if (root->left != nullptr){
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                rsl.push_back(root->val);
                root = root->right;
            }
        }
    }
};
