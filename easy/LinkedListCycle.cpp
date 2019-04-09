/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        auto slow = head;
        auto fast = head->next;
        while (slow != fast) {
            slow = slow->next;
            if (fast && fast->next && fast->next->next) {
                fast = fast->next->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
