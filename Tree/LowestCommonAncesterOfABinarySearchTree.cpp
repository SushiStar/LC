/*
 * Given a binary search tree (BST), find the lowest common (LCA) of two
 * given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: "The lowest common
 * ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendents (where we allow a node to be a
 * descendant of itself)."
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return root;
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

        if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
