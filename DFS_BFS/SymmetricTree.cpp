/*
 * Given a binary tree, check whether it is a mirror of itself.
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/25/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        std::deque<TreeNode*> stk[2];
        stk[0].push_back(root);
        int idx0{0}, idx1{1};
        while (!stk[0].empty() || !stk[1].empty()) {
            if (!isSymmetric(stk[idx0])) return false;
            while (!stk[idx0].empty()) {
                auto node = stk[idx0].front();
                stk[idx0].pop_front();
                if (node == nullptr) continue;
                stk[idx1].push_back(node->left);
                stk[idx1].push_back(node->right);
            }
            std::swap(idx0, idx1);
        }
        return true;
    }
private:
    bool isSymmetric(const std::deque<TreeNode*> &stk) {
        if(stk.empty()) return true;
        int lptr{0};
        int rptr(stk.size()-1);
        while (lptr < rptr) {
            auto leftNode = stk[lptr];
            auto rightNode = stk[rptr];
            if (leftNode && rightNode && leftNode->val != rightNode->val) return false; 
            if (leftNode == nullptr ^ rightNode == nullptr) return false;
            ++lptr;
            --rptr;
        }
        return true;
    }
};
