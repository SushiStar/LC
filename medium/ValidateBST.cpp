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
 * Date: Mar/25/2019
 * Author: Wei Du
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        std::list<TreeNode*> bfs{root};
        int max(0), min(0);
        bool valid(true);
        checkSubTree(root, max, min, valid);
        return valid;
    }
    void checkSubTree(TreeNode* root, int& max, int& min, bool& valid) {
        int max_ = root->val;
        int min_ = root->val;
        // bool valid_=true;
        valid = true;
        if (root->left) {
            checkSubTree(root->left, max_, min_, valid);
            if (!valid) return;
            if (max_ >= root->val) {
                valid = false;
                return;
            }
        }
        max = root->val > max_ ? root->val : max_;
        min = root->val < min_ ? root->val : min_;

        if (root->right) {
            checkSubTree(root->right, max_, min_, valid);
            if (!valid) return;
            if (min_ <= root->val) {
                valid = false;
                return;
            }
        }
        max = max > max_ ? max : max_;
        min = min < min_ ? min : min_;
    }
};
