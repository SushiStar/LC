/*
 * Given a binary tree, return the zigzag level order traversal of its
 * nodes' values. (ie, from left to right, then right to left for the
 * next level and alternate between).
 *
 * Date: 04/29/2020
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int>> ret{};
        if (!root) return ret;
        std::vector<TreeNode *> bfs[2];
        bfs[0].push_back(root);
        bool revs(false);
        while (!bfs[0].empty()) {
            std::vector<int> buffer{};
            for (auto p : bfs[0]) {
                buffer.push_back(p->val);
                if (p->left) bfs[1].push_back(p->left);
                if (p->right) bfs[1].push_back(p->right);
            }
            if (revs) std::reverse(buffer.begin(), buffer.end());
            revs = !revs;
            ret.push_back(buffer);
            bfs[0].clear();
            std::swap(bfs[0], bfs[1]);
        }
        return ret;
    }
};
