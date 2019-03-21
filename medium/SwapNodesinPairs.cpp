/*
 * Definition for singly-linked list.
 * public class ListNode{
 *      int val;
 *      ListNode* next;
 *      ListNode(int x) :{val = x;}
 * };
 *
 * Swap && update for the next iteration;
 * Author: Wei Du
 *
 * Date:Mar/20/2019
 */

class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;

        ListNode* flag_l;
        ListNode* A = head;
        ListNode* B = head->next;

        if(B) {
            A->next = B->next;
            B->next = A;
        } else {
            return head;
        }
        ListNode* new_head = B;

        flag_l = A;
        while(true) {
            A = A->next;
            if(!A) break;
            B = A->next;
            if(!B) break;

            // swap
            flag_l->next = B;
            A->next = B->next;
            B->next = A;
            flag_l = A;
        }
        return new_head; 
    }
};
