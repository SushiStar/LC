/*
 * Reverse a singly linked-list.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        auto tail(head);
        while (tail->next) {
            tail = tail->next;
        }
        reverse(head);
        return tail;
    }
    ListNode* reverse(ListNode* tail){
        if(tail->next) {
            auto t = reverse(tail->next);
            t->next = tail;
        }
        tail->next = nullptr;
        return tail;
    }
};
