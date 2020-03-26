/*
 * Definition of a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/25/2020
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result; 
        if (!root) return result;
        std::vector<TreeNode*> buffer[2];
        int idx0{0};
        int idx1{1};
        buffer[idx0].push_back(root);
        while (!buffer[idx0].empty()) {
            std::vector<int> level{};
            for (auto node : buffer[idx0]) {
                level.push_back(node->val);
                if (node->left) buffer[idx1].push_back(node->left);
                if (node->right) buffer[idx1].push_back(node->right);
            }
            result.push_back(level);
            buffer[idx0].clear();
            std::swap(idx0, idx1);
        }
        return result;
    }
};
