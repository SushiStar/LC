/*
 * Given a binary search tree and a node in it, find the in-order
 * successor of that node in the BST.
 *
 * The successor of a node p is the node with the smallest key
 * greater than p.val.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        // inorder traversal;
        if (!root) return nullptr;
        std::stack<TreeNode *> stk;
        stk.push(root);
        bool nxt(false);
        while (stk.top()->left)
            stk.push(stk.top()->left);
        while (!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            if (tmp == p)
                nxt = true;
            else if (nxt)
                return tmp;
            if (tmp->right) {
                stk.push(tmp->right);
                tmp = stk.top();
                while (tmp->left) {
                    stk.push(tmp->left);
                    tmp = stk.top();
                }
            }
        }
        return nullptr;
    }
};
