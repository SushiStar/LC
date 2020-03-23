/*
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST. Calling next(), will return the next
 * smallest number in the BST.
 * Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 *
 * next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree. You may assume that next() call will
 * always be valid, that is, there will be at least a next smallest number in
 * the BST when next() is called.
 *
 * Date: 03/23/2020
 *
 * Author: Wei Du
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (!root) {
            it = nullptr;
            return;
        }
        it = root;
        while (it) {
            stk.push(it);
            it = it->left;
        }
        it = stk.top();
    }

    /** @return the next smallest number */
    int next() {
        if (it == nullptr) return 0;
        int result = it->val;
        gotoNext();
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !stk.empty(); }

private:
    TreeNode *it;
    std::stack<TreeNode *> stk;
    void gotoNext() {
        if (it == nullptr) {
            return;
        }
        stk.pop();
        auto tmpIt = it->right;
        while (tmpIt) {
            stk.push(tmpIt);
            tmpIt = tmpIt->left;
        }

        if (stk.empty()) {
            it = nullptr;
        } else {
            it = stk.top();
        }
    }
};
