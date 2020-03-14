/*
 * Given a binary tree, determine whether its a valid binary search tree.
 *
 * Definition of a binary search tree node.
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    void isValidBST(TreeNode *root, long int minn, long int maxx) {
        if (!root) return true;
        if (root->val <= minn || root->val >= maxx) return false;
        return isValidBST(root->left, minn, root->val) &&
               isValidBST(root->right, root->val, maxx);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> stk;
        std::vector<int> vals;
        while(root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                vals.push_back(root->val);
                root = root->right;
            }
        }
        for (int i = 1; i < vals.size(); ++i){ 
            if (vals[i]<=vals[i-1]) return false;
        }
        return true;
    }
};
