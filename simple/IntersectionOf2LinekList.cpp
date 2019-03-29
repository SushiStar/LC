/*
 * Write a program, to find the node at which the intersection
 * of two singly linked list begins.
 *
 * Definition for singly-linked list.
 * struct ListNode{
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Date: Mar/28/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::unordered_map<ListNode*, int> storage;
        if(!headA || !headB ) return nullptr;
        while(headA){
            storage[headA] = 1;
            headA = headA->next;
        }
        while (headB) {
            if (storage[headB] == 1) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
