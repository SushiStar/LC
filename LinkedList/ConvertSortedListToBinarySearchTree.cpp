/*
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Date: 04/13/2020
 * Author: Wei Du
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        std::vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        return constructTree(vals, 0, vals.size() - 1);
    }

private:
    TreeNode *constructTree(const std::vector<int> &vals, int start, int end) {
        if (start > end) return nullptr;
        int mid((start + end) / 2);
        TreeNode *root = new TreeNode(vals[mid]);
        if (start == end) return root;

        root->left = constructTree(vals, start, mid - 1);
        root->right = constructTree(vals, mid + 1, end);
        return root;
    }
};
