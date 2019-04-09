/*
 * Sort a linked-list in O(nlogn) time using constant space complexity.
 *
 * Date: Apr/8/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto mid = getMiddle(head);
        auto next = mid->next;
        mid->next = nullptr;

        auto one = sortList(head);
        auto two = sortList(next);
        auto complete = merge(one, two);
        return complete;
    }

    ListNode* getMiddle(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* one, ListNode* two) {
        ListNode* dummyNode;
        ListNode* dummyEnd;

        dummyNode = one->val < two->val ? one : two;
        if (one->val < two->val) {
            dummyNode = one;
            one = one->next;
        } else {
            dummyNode = two;
            two = two->next;
        }
        dummyEnd = dummyNode;

        while (one && two) {
            if (one->val < two->val) {
                dummyEnd->next = one;
                one = one->next;
            } else {
                dummyEnd->next = two;
                two = two->next;
            }
            dummyEnd = dummyEnd->next;
        }
        if (!one) {  // one is empty
            dummyEnd->next = two;
        } else {
            dummyEnd->next = one;
        }
        return dummyNode;
    }
};
