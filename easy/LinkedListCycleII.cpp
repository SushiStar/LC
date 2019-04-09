/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return nullptr;
        std::unordered_map<ListNode*, int> mp;
        while (head) {
            if (!mp[head]) mp[head]++;
            else return head;
            head = head->next;
        }
        return nullptr;
    }
};
