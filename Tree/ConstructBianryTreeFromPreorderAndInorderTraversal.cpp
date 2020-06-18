/*
 * Given preorder and inorder traversals of a tree, construct the binary tree.
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        m_preorder = std::move(preorder);
        for (int i = 0; i < inorder.size(); ++i)
            idx[inorder[i]] = i;
        return buildTree(0, m_preorder.size()-1, 0, m_preorder.size()-1);
    }
private:
    vector<int> m_preorder;
    unordered_map<int, int> idx;
    TreeNode* buildTree(int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return nullptr;
        TreeNode* root = new TreeNode(m_preorder[preLeft]);
        if (preLeft == preRight)
            return root;
        int leftLength(idx[root->val] - inLeft);
        root->left = buildTree(preLeft+1, preLeft+leftLength, inLeft, idx[root->val]-1);
        root->right = buildTree(preLeft+leftLength+1, preRight, idx[root->val]+1, inRight);
        return root;
    }
};

class Solution1 {
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
