/*
 * Given a linked list, remove the n-the node from the end of list and return
 * its head.
 *
 * Given n will always be valid
 *
 * Definition of singly-linked list.
 * struct List Node {
 *      int val;
 *      ListNode* next;
 *      ListNode(int x): val(x), next(NULL) {}
 * };
 *
 * Author: Wei Du
 *
 * Date: 02/16/2020
 *
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *flag = new ListNode(0);
        flag->next = head;
        ListNode *temp = head;
        int counter = 0;

        // find node before target
        while (temp->next != nullptr) {
            if (counter >= n - 1) {
                flag = flag->next;
            }
            temp = temp->next;
            counter++;
        }

        if (flag->next == head) {
            auto res = head->next;
            delete head;
            return res;
        } else {
            auto tempp = flag->next;
            if (tempp != nullptr) {
                flag->next = temp->next;
            } else {
                flag->next = nullptr;
            }
            delete temp;
            return head;
        }
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *prelptr(nullptr), *lptr(head), *rptr(head);
        for (int i = 0; i < n - 1; ++i) {
            rptr = rptr->next; // n is always valid
        }
        while (rptr->next) {
            rptr = rptr->next;
            prelptr = lptr;
            lptr = lptr->next;
        }
        if (!prelptr) { // head is removed
            auto rlt = head->next;
            delete head;
            return rlt
        } else {
            prelptr->next = lptr->next;
            delete lptr;
        }
        return head;
    }
};
