/*
 * Given a linked list and a value x, partition it such that all
 * nodes less than x combefore nodes greater than or equal to x,
 *
 * You should preserve the original relative order of the nodes in
 * each of the two partitions.
 *
 * Definition for single-linked list:
 * struct ListNode {
 *     int val;
 *     int ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Date: Apri/5/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* newhead = new ListNode(-1);
        ListNode* newtail = newhead;
        ListNode* realhead(head);
        ListNode* prevhead(nullptr);
        while (realhead && realhead->val >= x) {
            prevhead = realhead;
            realhead = realhead->next;
        }
        if (!realhead) {
            return head;
        }
        newhead->next = head;
        newtail = prevhead ? prevhead : newtail;
        newtail->next = nullptr;
        head = realhead;
        auto now = realhead;
        auto prev = realhead;
        while (now) {
            if (now->val >= x) {
                newtail->next = now;
                newtail = newtail->next;
                prev->next = now->next;
                now = now->next;
                newtail->next = nullptr;
            } else {
                prev = now;
                now = now->next;
            }
        }
        prev->next = newhead->next;
        return head;
    }
};
