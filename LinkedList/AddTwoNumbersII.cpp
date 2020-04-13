/*
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two nubmers do not contain any leading zero, except the
 * nubmer 0 itself.
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
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        // reverse two lists
        std::stack<ListNode *> lst1;
        std::stack<ListNode *> lst2;
        std::stack<ListNode *> rlt;
        while (l1 || l2) {
            if (l1) {
                lst1.push(l1);
                l1 = l1->next;
            }
            if (l2) {
                lst2.push(l2);
                l2 = l2->next;
            }
        }

        int carry(0);
        while (!lst1.empty() || !lst2.empty()) {
            int sum{carry};
            if (!lst1.empty()) {
                sum += lst1.top()->val;
                lst1.pop();
            }
            if (!lst2.empty()) {
                sum += lst2.top()->val;
                lst2.pop();
            }
            carry = sum / 10;
            sum %= 10;
            rlt.push(new ListNode(sum));
        }
        ListNode *head = new ListNode(carry);
        ListNode *tail{head};
        while (!rlt.empty()) {
            tail->next = rlt.top();
            rlt.pop();
            tail = tail->next;
        }
        return carry ? head : head->next;
    }
};
