/**
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Definition for singly linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *rlt = l1, prel1(nullptr);
        int extra(0);
        while (extra || l2) {
            if (!l1) {
                l1 = new ListNode(0);
                prel1->next =  l1;
            }
            int sum = extra + l1->val + (l2 ? l2->val : 0);
            extra = sum / 10;
            l1->val = sum % 10;

            prel1 = l1;
            l1 = l1->next;
            l2 = l2 ? l2->next : l2;
        }
        return rlt;
    }
};
