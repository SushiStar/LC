/*
 * Given a binary tree, check whether its a mirror of it self.
 * Definition of a binary tree node.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        // at least 2 leves
        // BFS
        std::vector<TreeNode*> level{root};

        while (!level.empty()) {
            int size = level.size();

            for (int i = 0; i < size; ++i) {
                if ((level[i] == nullptr) ^ (level[size - 1 - i] == nullptr))
                    return false;

                if (level[i] && level[size - 1 - i]) {
                    if (level[i]->val == level[size - 1 - i]->val) {
                        level.push_back(level[i]->left);
                        level.push_back(level[i]->right);
                    } else {
                        return false;
                    }
                }
            }
            // pop out last level
            level.erase(level.begin(), level.begin() + size);
        }
        return true;
    }
};
