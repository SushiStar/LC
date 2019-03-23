/*
 * Definition of a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Mar/22/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        res.push_back(std::vector<int>{root->val});

        std::vector<TreeNode*> level{root};
        while (true) {
            auto level = levelTravel(level);
            if (level.size() > 0) {
                std::vector<int> nextnum;
                for (auto tmp : next) nextnum.push_back(tmp->val);
                res.push_back(nextnum);
            } else {
                break;
            }
        }
        return res;
    }

    vector<TreeNode*> levelTravel(vector<TreeNode*>& currentL) {
        std::vector<TreeNode*> nextL;
        for (auto tmp : currentL) {
            if (tmp->left) nextL.push_back(tmp->left);
            if (tmp->right) nextL.push_back(tmp->right);
        }
        return nextL;
    }
};
