/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Date: 04/13/2020
 * Author: Wei Du
 */
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        std::vector<ListNode *> vct;
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head) return nullptr;
        vct.push_back(head);
        head = head->next;
        while (head) {
            if (head->val != val) {
                vct.back()->next = head;
                vct.push_back(head);
            }
            head = head->next;
        }
        vct.back()->next = nullptr;
        return vct[0];
    }
};
