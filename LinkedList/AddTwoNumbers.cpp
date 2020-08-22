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
 *
 * Date: 03/30/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *rlt = new ListNode(0);
    ListNode *tail(rlt);
    int carry{0};
    while (carry || l1 || l2) {
      int val1{0}, val2{0};
      if (l1) {
        val1 = l1->val;
        l1 = l1->next;
      }
      if (l2) {
        val2 = l2->val;
        l2 = l2->next;
      }
      int sum = carry + val1 + val2;
      carry = sum / 10;
      ListNode *tmp = new ListNode(sum % 10);
      tail->next = tmp;
      tail = tmp;
    }
    return rlt->next;
  }
};
