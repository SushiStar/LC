/*
 * Given an integer n, generate all structurally unique BST's that store
 * values 1...n.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/14/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode *>{};
        }
        std::vector<TreeNode *> result = generateSubTrees(1, n);
        return result;
    }

private:
    std::vector<TreeNode *> generateSubTrees(int left, int right) {
        std::vector<TreeNode *> result;
        if (left > right) {
            result.push_back(nullptr);
            return std::move(result);
        }

        if (left == right) {
            TreeNode *thisNode = new TreeNode(left);
            result.push_back(thisNode);
            return std::move(result);
        }

        for (int i = left; i <= right; ++i) {
            auto lSubTree = generateSubTrees(left, i - 1);
            auto rSubTree = generateSubTrees(i + 1, right);
            for (auto lst : lSubTree) {
                for (auto rst : rSubTree) {
                    TreeNode *thisNode = new TreeNode(i);
                    thisNode->left = lst;
                    thisNode->right = rst;
                    result.push_back(thisNode);
                }
            }
        }
        return std::move(result);
    }
};
