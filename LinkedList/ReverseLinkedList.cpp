/*
 * Reverse a singly linked-list.
 *
 * Date: 03/30/2020
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        // iteratively
        ListNode* ptrL{nullptr};
        ListNode* ptrM{head};
        ListNode* ptrR{head->next};
        while (ptrR){ 
            ptrM->next = ptrL;
            ptrL = ptrM;
            ptrM = ptrR;
            ptrR = ptrR->next;
        }
        ptrM->next = ptrL;
        return ptrM;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        // recursively
        auto hd = reverseList(head->next);
        if (!hd)
            return head;
        head->next->next = head;
        head->next = nullptr;
        return hd;
    }
};
