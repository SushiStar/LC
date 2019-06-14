/*
 * Given a binary search tree, write a function kthsmallest to find the kth 
 * smallest element in it.
 * You may assume k is always valid, 1 <= k <= BST'S total number of elements
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Jun/14/2019
 * Author: Wei Du
 *
 */
#include<stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // root is assumed to be valid.
        // in order traverse
        int counter(0);
        TreeNode* temp{root};
        std::stack<TreeNode*> sk;
        while (true) {
            while (temp) {
                sk.push(temp);
                temp = temp->left;
            }
            ++counter;
            temp = sk.top();
            if (counter == k) break;
            sk.pop();
            temp = temp->right;
        }
        return temp->val;
    }
};
