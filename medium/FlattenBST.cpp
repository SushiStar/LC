/*
 * Given a binary tree, flatten it to a linked list in place.
 *
 * Date: Apr/8/2019
 * Author: Wei Du
 */
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
