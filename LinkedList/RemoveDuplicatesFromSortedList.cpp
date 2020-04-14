/*
 * Given a sorted linked list, delete all duplicates such that each
 * element appear only once.
 *
 * Date: 04/13/2020
 * Author: Wei Du
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *buffer{head->next};
        std::vector<ListNode *> vct{head};
        while (buffer) {
            if (buffer->val != vct.back()->val) {
                vct.back()->next = buffer;
                vct.push_back(buffer);
            }
            buffer = buffer->next;
        }
        vct.back()->next = nullptr;
        return head;
    }
};
