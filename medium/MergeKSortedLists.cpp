/*
 * Definition for singly linked-list
 * struct ListNode{
 *      int val;
 *      ListNode* next;
 *      ListNode(int x):vax(x),next(nullptr){}
 * };
 * Merge K sorted linked lists;
 *
 * Another solution: priority queue.
 *
 * Author: Wei Du
 * Date: Mar/12/2019
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return nullptr;

        ListNode* head = new ListNode(-1000);
        ListNode* tail = head;
        int alldone = 0;

        int current_min;
        int min_val=INT_MAX;
        while (size == alldone) {
            for (int i = 1; i < size; ++i) {
                if(lists[i] != nullptr) {
                    if(min_val > lists[i]->val) {
                        min_val = lists[i]->val;
                        current_min = i;
                    }
                } 
            }
            tail->next = lists[current_min];
            tail=tail->next;
            lists[current_min]=lists[current_min]->next;
            if(lists[current_min] == nullptr) ++alldone;
        }
        return head->next;
    }
};
