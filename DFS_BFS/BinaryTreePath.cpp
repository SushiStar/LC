/*
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        std::vector<string> rlt{};
        if (!root) return rlt;
        std::vector<int> buffer{};
        dfs(root, buffer, rlt);
        return rlt;
    }

private:
    void dfs(TreeNode *root, std::vector<int> &buffer,
             std::vector<std::string> &rlt) {
        buffer.push_back(root->val);
        if (!root->left && !root->right) {
            std::string solution(std::to_string(buffer[0]));
            for (int i = 1; i < buffer.size(); ++i) {
                solution = solution + "->" + std::to_string(buffer[i]);
            }
            rlt.push_back(solution);
        }
        if (root->left) {
            dfs(root->left, buffer, rlt);
        }
        if (root->right) {
            dfs(root->right, buffer, rlt);
        }
        buffer.pop_back();
    }
};
