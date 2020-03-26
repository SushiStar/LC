/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Date: 03/25/2020
 * Author: Wei Du
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        std::vector<TreeNode *> buffer[2];
        int result{0};
        int idx0{0};
        int idx1{1};
        buffer[idx0].push_back(root);
        while (!buffer[idx0].empty()) {
            ++result;
            for (auto node : buffer[idx0]) {
                if (!node->left && !node->right) return result;
                if (node->left) {
                    buffer[idx1].push_back(node->left);
                }
                if (node->right) {
                    buffer[idx1].push_back(node->right);
                }
            }
            buffer[idx0].clear();
            std::swap(idx0, idx1);
        }
        return result;
    }
};
