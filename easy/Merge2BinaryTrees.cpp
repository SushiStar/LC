/*
 * Given two binary trees and imagine that when you put one of them to cover the other,
 * some nodes of the two trees are overlapped while the others are not.  You need to 
 * merge them into a new binary tree. The merge rule is that if two nodes overlap, then
 * sum node values up as the new value of the merged node. Otherwise, the NOT null node
 * will be used as the node of new tree.
 *
 * Date: Apr/12/2019
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        
        auto l = mergeTrees(t1->left, t2->left);
        auto r = mergeTrees(t1->right, t2->right);
        t1->left = l;
        t1->right = r;
        t1->val += t2->val;
        return t1;
    }
};
