/*
 * Given the root of a binary tree with N nodes, each node in the
 * tree has node.val coins, and there are N coins total.
 *
 * In one move, we may choose two adjacent nodes and move one coin from
 * one node to another. (The move may be from parent to child, or from
 * child to parent.)
 *
 * Return the number of moves required to make every node have exactly
 * one coin.
 *
 * Date: 04/01/2020
 * Author: Wei Du
 */

class Solution {
public:
    int distributeCoins(TreeNode *root) {
        if (!root) return 0;
        // the left is extra;
        root->val -= 1;
        // post order traversal;
        int leftOperation(distributeCoins(root->left));
        int rightOperation(distributeCoins(root->right));
        // positive get money, otherwise lose money
        int leftTransaction{0};
        int rightTransaction{0};
        if (root->left) leftTransaction = root->left->val;
        if (root->right) rightTransaction = root->right->val;
        // Total as to root
        root->val = root->val + leftTransaction + rightTransaction;
        return leftOperation + rightOperation + std::abs(leftTransaction) +
               std::abs(rightTransaction);
    }
};
