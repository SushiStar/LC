/*
 * Given a binary tree, flatten it to a linked list in place.
 *
 * Date: 04/01/2020
 * Author: Wei Du
 */
// recursive version
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root) {
            flatten(root->left);
            flatten(root->right);
            auto ptr = root->left;
            if (!ptr) {  // left child is empty
                return;
            }
            while (ptr->right) {
                ptr = ptr->right;
            }
            ptr->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

// iterative version
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        // pre order
        std::stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* curr{nullptr};
        TreeNode* pre{nullptr};
        while (!stk.empty()){ 
            if (pre) {
                pre->right = stk.top();
                pre->left = nullptr;
            }
            curr = stk.top();
            stk.pop();
            if (curr->right)
                stk.push(curr->right);
            if (curr->left)
                stk.push(curr->left);
            pre = curr;
        }
    }
};
