/*
 * Given preorder and inorder traversals of a tree, construct the binary tree.
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        std::unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        auto res = helper(preorder, mp, 0, 0, preorder.size() - 1);
        return res;
    }

private:
    TreeNode *helper(vector<int> &preorder, std::unordered_map<int, int> &mp,
                     int preStart, int inStart, int inEnd) {
        if (preStart >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }
        int bk = mp[preorder[preStart]];
        TreeNode *root = new TreeNode(preorder[preStart]);
        TreeNode *lft = helper(preorder, mp, preStart + 1, inStart, bk - 1);
        // the next preStart = preStart - (num of elements on the left =
        // bk-inStart +1)
        TreeNode *rht =
            helper(preorder, mp, preStart + bk - inStart + 1, bk + 1, inEnd);
        root->left = lft;
        root->right = rht;
        return root;
    }
};

// iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root(nullptr);
        if (preorder.empty()) return root;
        root = new TreeNode(preorder[0]);

        std::stack<TreeNode *> stk;
        stk.push(root);

        int idxIn{0};
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *curr = stk.top();
            if (curr->val != inorder[idxIn]) {
                TreeNode *tmp = new TreeNode(preorder[i]);
                curr->left = tmp;
                stk.push(tmp);
                curr = stk.top();
            } else { // curr->val == inorder[idxIn];
                while (!stk.empty() && stk.top()->val == inorder[idxIn]) {
                    curr = stk.top();
                    stk.pop();
                    ++idxIn;
                }
                curr->right = new TreeNode(preorder[i]);
                stk.push(curr->right);
            }
        }
        return root;
    }
};
