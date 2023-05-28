/*
 * Given a slingly linked list, determine if it is a palindrome.
 *
 * Date: 04/28/2020
 * Author: Wei Du
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return true;
    auto head2 = reverseHalf(head);
    return isPalindrome(head, head2);
  }

 private:
  ListNode *reverseHalf(ListNode *head) {
    auto fast(head);
    auto slow(head);
    while (fast) {
      fast = fast->next;
      slow = slow->next;
      if (fast) fast = fast->next;
    }
    auto pre(slow);
    slow = slow->next;
    pre->next = nullptr;
    ListNode *nxt(nullptr);
    while (slow) {
      nxt = slow->next;
      slow->next = pre;
      pre = slow;
      slow = nxt;
    }
    return pre;
  }
  bool isPalindrome(ListNode *head1, ListNode *head2) {
    while (head1 && head2) {
      if (head1->val == head2->val) {
        head1 = head1->next;
        head2 = head2->next;
      } else {
        return false;
      }
    }
    return true;
  }
};
