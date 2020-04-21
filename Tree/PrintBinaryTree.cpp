/*
 * Print a binary tree in an m*n 2D string array following these rules:
 * 1. The row number m should be equal to the height of the given binary tree.
 * 2. The column number n should always be an odd number.
 * 3. The root node's value (in string format) should be put in the exactly
 * middle of the first row it can be put. The column and the row where the root
 * node belongs will separate the rest space into two parts (left-bottom part
 * and right-bottom part). You should print the left subtree in the left-bottom
 * and right-bottom part. The left-bottom part and the right-bottom part should
 * have the same size. Even if one subtree is none while the other is not, you
 * don't need to print anything for the non subtree but still need to leave the
 * space as large as that for the other subtree. However, if two subtrees are
 * none, then you don't need to leave space for both of them.
 * 4. Each unused space should contain an empty string "".
 * 5. Print the subtrees following the same rules.
 *
 * Date: 04/20/2020
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
    vector<vector<string>> printTree(TreeNode *root) {
        std::vector<std::vector<std::string>> rlt{};
        if (!root) return rlt;
        int depth = getDepth(root);
        int row(depth);
        int col(std::pow(2, depth) - 1);
        int interValLength(col);
        rlt.resize(row, std::vector<std::string>(col, ""));
        rlt[0][col / 2] = std::to_string(root->val);
        interValLength = interValLength / 2 - 1;
        std::unordered_map<TreeNode *, int> idx;
        idx[root] = col / 2;
        std::vector<TreeNode *> bfs[2];
        bfs[0].push_back(root);
        for (int i = 1; i <= depth; ++i) {
            for (auto &p : bfs[0]) {
                if (p->left || p->right) {
                    int pidx = idx[p];
                    if (p->left) {
                        idx[p->left] = pidx - (interValLength / 2 + 1);
                        bfs[1].push_back(p->left);
                        rlt[i][idx[p->left]] = std::to_string(p->left->val);
                    }
                    if (p->right) {
                        idx[p->right] = pidx + (interValLength / 2 + 1);
                        bfs[1].push_back(p->right);
                        rlt[i][idx[p->right]] = std::to_string(p->right->val);
                    }
                }
            }
            interValLength = interValLength / 2 - 1;
            bfs[0].clear();
            std::swap(bfs[0], bfs[1]);
        }
        return rlt;
    }

private:
    int getDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + std::max(getDepth(root->left), getDepth(root->right));
    }
};
