/*
 * Given a linked list, reverse the nodes of a linked list k at a time
 * and returns its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left
 * out nodes in the end should remain as it is.
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may
 * be changed
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        ListNode *lhs(head);
        ListNode *rhs(head);
        int counter(k);
        --counter; // the first one
        while (counter > 0 && rhs) {
            rhs = rhs->next;
            --counter;
        }
        if (!rhs) return head;

        // get the rest seg
        ListNode *rest{reverseKGroup(rhs->next, k)};

        // reverse current k
        rhs->next = nullptr;
        ListNode *nxtLhs(lhs->next);
        ListNode *nxtNxtLhs(nxtLhs->next);
        lhs->next = rest;
        while (nxtLhs) {
            nxtLhs->next = lhs;
            lhs = nxtLhs;
            nxtLhs = nxtNxtLhs;
            if (nxtNxtLhs) nxtNxtLhs = nxtNxtLhs->next;
        }
        return rhs;
    }
};
