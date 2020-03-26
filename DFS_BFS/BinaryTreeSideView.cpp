/*
 * Given a binary tree, imagine yourself standing on the right side of it.
 * Return the values of the nodes you can see ordered from top to bottom.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/25/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result{};
        if (!root) return result;
        std::deque<TreeNode*> dq[2];
        int idx0{0};
        int idx1{1};
        
        // do BFS
        dq[0].push_back(root);
        while (!dq[idx0].empty()){ 
            result.push_back(dq[idx0].back()->val);
            while (!dq[idx0].empty()) {
                auto node = dq[idx0].front();
                dq[idx0].pop_front();
                if (node->left) 
                    dq[idx1].push_back(node->left);
                if (node->right)
                    dq[idx1].push_back(node->right);
            }
            std::swap(idx0, idx1);
        }
        return result;
    }
};
