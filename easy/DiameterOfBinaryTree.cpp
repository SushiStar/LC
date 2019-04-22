/*
 * Given a binary tree, you need to compute the length of the diameter
 * of the tree. The diameter of a bianry tree is the length of the longest
 * path between any two nodes in a tree.
 *
 * Note: the length of path between 2 nodes is represented by the number
 * of edges between them.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include<cmath>

class Solution {
private:
    int length;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        length=0;
        auto k = traverse(root);
        return length;
    }
    int traverse(TreeNode* root) {
        if (!root) return -1;
        auto left = traverse(root->left);
        auto right = traverse(root->right);
        length = std::max(length, left+right+2);
        return std::max(left,right)+1;
    }
};
